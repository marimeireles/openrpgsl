#include <QApplication>
#include <QWidget>
#include <vector>

#include "mainWindow.h"
#include "player.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    QApplication app(argc, argv);

    Interface window;

    window.resize(800, 600);
    window.setWindowTitle("Open RPG - Sound Library");
    window.show();

    return app.exec();
}
