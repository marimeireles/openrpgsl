#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QLabel>
#include <vector>
#include <map>
#include <QString>
#include <QDialog>

#include "player.h"

using namespace std;

class Interface : public QWidget
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

    void open();
    void createPlayer();
    void createLib(Player *player);
    void createAlbumLayout(QString albumName);
    void addTrackToAlbumLayout(QString albumName, QString trackName, Player *player);
    bool isAlbumAdded(QString albumName);

private:
    QVBoxLayout *mainLayout = nullptr;
    QHBoxLayout *optionsLayout = nullptr;
    QHBoxLayout *libLayout = nullptr;
    vector<QVBoxLayout*> albumLayouts;
    QVBoxLayout *tracksLayout = nullptr;
    vector<Player*> players;
    map<QString, int> albumInfo;
};
