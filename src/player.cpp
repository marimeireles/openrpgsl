#include <QMediaMetaData>
#include <QMediaService>
#include <QtWidgets>
#include <QSlider>
#include <QString>

#include "include/player.h"
#include "include/playerControls.h"

using namespace std;

Player::Player(QWidget *parent) : QWidget(parent)
{
    m_player = new QMediaPlayer(this);
    m_player->setAudioRole(QAudio::MusicRole);

    //emits signal when metadata is ready
    connect(m_player, QOverload<>::of(&QMediaPlayer::metaDataChanged), this, &Player::metaDataChanged);

    //creates slider
    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setRange(0, m_player->duration() / 1000);
    m_labelDuration = new QLabel();
    connect(m_slider, &QSlider::sliderMoved, this, &Player::seek);
    connect(m_player, &QMediaPlayer::durationChanged, this, &Player::durationChanged);
    connect(m_player, &QMediaPlayer::positionChanged, this, &Player::positionChanged);

    PlayerControls *controls = new PlayerControls(this);
    controls->setState(m_player->state());
    controls->setVolume(m_player->volume());
    controls->setMuted(controls->isMuted());

    connect(controls, &PlayerControls::play, m_player, &QMediaPlayer::play);
    connect(controls, &PlayerControls::pause, m_player, &QMediaPlayer::pause);
    connect(controls, &PlayerControls::stop, m_player, &QMediaPlayer::stop);
    connect(controls, &PlayerControls::changeVolume, m_player, &QMediaPlayer::setVolume);
    connect(controls, &PlayerControls::changeMuting, m_player, &QMediaPlayer::setMuted);

    connect(m_player, &QMediaPlayer::stateChanged, controls, &PlayerControls::setState);
    connect(m_player, &QMediaPlayer::volumeChanged, controls, &PlayerControls::setVolume);
    connect(m_player, &QMediaPlayer::mutedChanged, controls, &PlayerControls::setMuted);

    QHBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addStretch(1);
    controlLayout->addWidget(controls);
    controlLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_slider);
    hLayout->addWidget(m_labelDuration);
    mainLayout->addLayout(hLayout);
    mainLayout->addLayout(controlLayout);

    setLayout(mainLayout);
}

Player::~Player()
{
}

QString Player::getAlbumName()
{
    return m_player->metaData(QMediaMetaData::AlbumTitle).toString();
}

QString Player::getTrackName()
{
    return m_player->metaData(QMediaMetaData::Title).toString();
}

void Player::setMedia(const QMediaContent &media, QIODevice *stream)
{
    m_player->setMedia(media, stream);
}

void Player::metaDataChanged()
{
    if (m_player->isMetaDataAvailable())
        emit metaDataAvailable(this);
}

void Player::seek(int seconds)
{
    m_player->setPosition(seconds * 1000);
}

void Player::durationChanged(qint64 duration)
{
    m_duration = duration / 1000;
    m_slider->setMaximum(m_duration);
}

void Player::positionChanged(qint64 progress)
{
    if (!m_slider->isSliderDown())
        m_slider->setValue(progress / 1000);

    updateDurationInfo(progress / 1000);
}

void Player::updateDurationInfo(qint64 currentInfo)
{
    QString tStr;
    if (currentInfo || m_duration) {
        QTime currentTime((currentInfo / 3600) % 60, (currentInfo / 60) % 60,
            currentInfo % 60, (currentInfo * 1000) % 1000);
        QTime totalTime((m_duration / 3600) % 60, (m_duration / 60) % 60,
            m_duration % 60, (m_duration * 1000) % 1000);
        QString format = "mm:ss";
        if (m_duration > 3600)
            format = "hh:mm:ss";
        tStr = currentTime.toString(format) + " / " + totalTime.toString(format);
    }
    m_labelDuration->setText(tStr);
}

