#include <QApplication>
#include "gamemanager.h"

GameManager* gm;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gm = new GameManager();
    gm->mainMenuDisplay();

    return a.exec();
}
