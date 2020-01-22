#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QCoreApplication>
#include <QDebug>
#include "player.h"
#include "enemy.h"
#include "environment.h"

class GameManager: public QGraphicsView
{
    Q_OBJECT
public:
    GameManager(QWidget* parent=NULL);

    void mainMenuDisplay();
    void pauseMenuDisplay();

    void hudLoad();

    void changeScoreHUD();
    void changeLivesHUD();

    QGraphicsScene* scene;
    QGraphicsScene* scenePause;
    QGraphicsScene* sceneGame;
    QGraphicsTextItem* scoreText;
    QGraphicsTextItem* livesText;

    Environment* environment;

    Player* player; //needs scene to load itself and progress itself?
    Enemy* ghost1;
    Enemy* ghost2;
    Enemy* ghost3;
    Enemy* ghost4;
public slots:
    void newGame();
    void quitGame();
    void pauseGame();
    void resumeGame();
    void goMainMenu();

};

#endif // GAMEMANAGER_H
