#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QCoreApplication>
#include <QDebug>
#include <QImage>
#include <QLabel>
#include <QApplication>
#include "player.h"
#include "enemy.h"
#include "environment.h"
#include <Windows.h>

class GameManager: public QGraphicsView
{
    Q_OBJECT
public:
    GameManager(QWidget* parent=NULL);

    void mainMenuDisplay();
    void pauseMenuDisplay();

    void hudLoad();

    void environmentUI();

    void changeScoreHUD();
    void changeLivesHUD();

    void update();

    bool gameOver();
    int i;


    QGraphicsScene* scene;
    QGraphicsScene* scenePause;
    QGraphicsScene* sceneGame;
    QGraphicsTextItem* scoreText;
    QGraphicsTextItem* livesText;

    Environment* environment;

    std::list<Character*> characters;

    Player* player; //needs scene to load itself and progress itself?
    Enemy* ghost1;
    Enemy* ghost2;
    Enemy* ghost3;
    Enemy* ghost4;

    bool isPlaying;
public slots:
    void newGame();
    void quitGame();
    void pauseGame();
    void resumeGame();
    void goMainMenu();
    void keyPressEvent(QKeyEvent *event);

};

#endif // GAMEMANAGER_H
