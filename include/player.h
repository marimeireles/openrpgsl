#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QString>
#include <QMediaMetaData>
#include <QMediaService>
#include <QtWidgets>
#include <QSlider>
#include <QString>


QT_BEGIN_NAMESPACE
class QAbstractItemView;
class QLabel;
class QMediaPlayer;
class QModelIndex;
class QPushButton;
class QSlider;
class QStatusBar;
class QAudioProbe;
QT_END_NAMESPACE

using namespace std;

class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = nullptr);
    ~Player();

    QString getAlbumName();
    QString getTrackName();

    // QBoxLayout *layout = nullptr; //should I make it a heir instead of making it public?

signals:
    void metaDataAvailable(Player* player);

public slots:
    void setMedia(const QMediaContent &media, QIODevice *stream = nullptr);
    void metaDataChanged();

private slots:
    void seek(int seconds);
    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);

private:
    void updateDurationInfo(qint64 currentInfo);
    QMediaPlayer *m_player = nullptr;
    QString trackName;
    QLabel *m_coverLabel = nullptr;
    QSlider *m_slider = nullptr;
    QStatusBar *m_statusBar = nullptr;

    QLabel *m_labelDuration = nullptr;

    QLabel *m_statusLabel = nullptr;


    QString m_trackInfo;

    QString m_statusInfo;

    qint64 m_duration;

};

#endif