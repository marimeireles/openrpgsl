#include <QWidget>
#include <QtWidgets>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QMainWindow>

#include "include/player.h"
#include "include/mainWindow.h"

Interface::Interface(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    mainLayout = new QVBoxLayout;
    optionsLayout = new QHBoxLayout;
    libLayout = new QHBoxLayout;

    createActions();
    createMenus();

    QPushButton *openButton = new QPushButton(tr("Open"));
    optionsLayout->addWidget(openButton);

    connect(openButton, &QPushButton::clicked, this, &Interface::open);

    mainLayout->addLayout(optionsLayout);
    mainLayout->addLayout(libLayout);
    centralWidget->setLayout(mainLayout);
}

#ifndef QT_NO_CONTEXTMENU
void Interface::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.exec(event->globalPos());
}
#endif

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

void Interface::save()
{
    printf("🐗\n");
}

void Interface::load()
{
    printf("🦊\n");
}

void Interface::help()
{
    QMessageBox::about(this, tr("Help Menu"),
            tr("<b>Categories:</b> The categories in this library are aggrouped"
                " by the track's album name.<br> <b>Track names</b>: Have the "
                "same name as the track's name. <br> If you encounter any weird"
                " error while running this app, drop me a message"
                "mariana@psychonautgirl.space"));
}

void Interface::about()
{
    QMessageBox::about(this, tr("About Menu"),
            tr("This is an Open RPG Sound Library for RPG players! Feel free to"
                " use this project however you want. Just keep in mind that this"
                " is under the GNU GPL 3 license!"));
}

void Interface::createActions()
{
    openAct = new QAction(tr("&Open track"), this);
    openAct->setStatusTip(tr("Loads one track into the app"));
    connect(openAct, &QAction::triggered, this, &Interface::open);
    openAct->setShortcut(tr("CTRL+O"));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setStatusTip(tr("Save current state of the library"));
    connect(saveAct, &QAction::triggered, this, &Interface::save);
    saveAct->setShortcut(tr("CTRL+S"));

    loadAct = new QAction(tr("&Load"), this);
    loadAct->setStatusTip(tr("Loads a previously saved library state"));
    connect(loadAct, &QAction::triggered, this, &Interface::load);
    loadAct->setShortcut(tr("CTRL+L"));

    helpAct = new QAction(tr("&Interface explanation and contact"), this);
    helpAct->setStatusTip(tr("Show the application's help box"));
    helpAct->setShortcut(tr("CTRL+H"));
    connect(helpAct, &QAction::triggered, this, &Interface::help);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &Interface::about);
}

void Interface::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(loadAct);

    infoMenu = menuBar()->addMenu(tr("&Help"));
    infoMenu->addAction(helpAct);
    infoMenu = menuBar()->addMenu(tr("&About"));
    infoMenu->addAction(aboutAct);
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
