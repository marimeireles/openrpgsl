#include <QApplication>
#include <QWidget>
#include <QMediaMetaData>
#include <QMediaService>
#include <QtWidgets>
#include <QDialog>
#include <QHBoxLayout>
#include <QFrame>

#include "include/player.h"
#include "include/mainWindow.h"

Interface::Interface(QWidget *parent) : QWidget(parent) {

    mainLayout = new QVBoxLayout;
    optionsLayout = new QHBoxLayout;
    libLayout = new QHBoxLayout;

    QPushButton *openButton = new QPushButton(tr("Open"), this);
    optionsLayout->addWidget(openButton);

    connect(openButton, &QPushButton::clicked, this, &Interface::open);

    mainLayout->addLayout(optionsLayout);
    mainLayout->addLayout(libLayout);
    setLayout(mainLayout);
}

void Interface::open()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Files"));
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
    if (fileDialog.exec() == QDialog::Accepted)
    {
        QList<QUrl> urlList = fileDialog.selectedUrls();
        createPlayer();
        for (auto url : urlList)
            players.back()->setMedia(url);
    }
}

void Interface::createPlayer()
{
    Player *player = new Player;
    players.push_back(player);
    connect(player, &Player::metaDataAvailable, this, &Interface::createLib);
}

void Interface::createLib(Player *player)
{
    QString albumName = player->getAlbumName();
    QString trackName = player->getTrackName();

    if (isAlbumAdded(albumName))
    {
        addTrackToAlbumLayout(albumName, trackName, player);
    }
    else
    {
        createAlbumLayout(albumName);
        addTrackToAlbumLayout(albumName, trackName, player);
    }
}

void Interface::createAlbumLayout(QString albumName)
{
    //creates frame
    QLabel *frame = new QLabel();
    frame->setFrameStyle(QFrame::Box | QFrame::Raised);

    QVBoxLayout* albumLayout = new QVBoxLayout;
    QVBoxLayout* albumTracksLayout = new QVBoxLayout;
    QLabel *labelAlbumName = new QLabel();

    //adds album name to layout
    labelAlbumName->setText(albumName);
    labelAlbumName->setAlignment(Qt::AlignTop);
    labelAlbumName->setFixedHeight(20);
    albumLayout->addWidget(labelAlbumName);
    albumLayout->addLayout(albumTracksLayout);
    albumLayout->addStretch();

    frame->setLayout(albumLayout);

    //adds album layout to the library layout
    this->libLayout->addWidget(frame);

    //creates a vector of albuns that are accessible by the tracks
    this->albumLayouts.push_back(albumTracksLayout);

    //updates the map that contains album info
    this->albumInfo[albumName] = this->albumLayouts.size()-1;
}

void Interface::addTrackToAlbumLayout(QString albumName, QString trackName, Player *player)
{
    //initializes track's layouts
    QHBoxLayout *individualTrackLayout = new QHBoxLayout;
    QVBoxLayout *trackTitleLayout = new QVBoxLayout;
    QVBoxLayout *playerControlsLayout = new QVBoxLayout;

    //creates frame
    QLabel *frame = new QLabel();
    frame->setFrameStyle(QFrame::Box | QFrame::Raised);

    individualTrackLayout->addLayout(trackTitleLayout);
    individualTrackLayout->addLayout(playerControlsLayout);
    individualTrackLayout->setAlignment(Qt::AlignTop);

    //adds track name to layout
    QLabel *labelTrackName = new QLabel();
    labelTrackName->setText(trackName);
    trackTitleLayout->addWidget(labelTrackName);

    playerControlsLayout->addWidget(player);
    frame->setLayout(individualTrackLayout);
    frame->setFixedHeight(120);

    //adds tracks layouts to the album layout
    this->albumLayouts[this->albumInfo[albumName]]->addWidget(frame);
}

bool Interface::isAlbumAdded(QString albumName)
{
    auto search = albumInfo.find(albumName);
    if (search != albumInfo.end()) return true;
    else return false;
}

Interface::~Interface()
{
}
