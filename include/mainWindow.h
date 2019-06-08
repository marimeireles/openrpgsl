#include <QWidget>
#include <vector>
#include <map>
#include <QString>

#include "player.h"

using namespace std;

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

    void createPlayer();
    void createLib(Player *player);
    void createAlbumLayout(QString albumName);
    void addTrackToAlbumLayout(QString albumName, QString trackName,
                               Player *player);
    bool isAlbumAdded(QString albumName);

private:
    /*menu*/
    void open();
    void save();
    void load();
    void about();
    void help();
    void createActions();
    void createMenus();

    /*menu options*/
    QMenu *fileMenu = nullptr;
    QMenu *infoMenu = nullptr;
    QAction *openAct = nullptr;
    QAction *saveAct = nullptr;
    QAction *loadAct = nullptr;
    QAction *aboutAct = nullptr;
    QAction *helpAct = nullptr;
    QLabel *infoLabel = nullptr;
    vector<QUrl> tracksLocations;

    /*lib layout*/
    QVBoxLayout *mainLayout = nullptr;
    QHBoxLayout *optionsLayout = nullptr;
    QHBoxLayout *libLayout = nullptr;
    vector<QVBoxLayout*> albumLayouts;
    QVBoxLayout *tracksLayout = nullptr;
    vector<Player*> players;
    map<QString, int> albumInfo;
    bool interfaceIsEmpty = true;

    QLabel *helpScreen = new QLabel();
};
