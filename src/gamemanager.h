#pragma once

// if running on Windows
// #include <Windows.h>

// if running on Mac
#include <unistd.h>

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
#include <thread>
#include <QTimer>
#include "vector.h"
#include "item.h"
#include "gold.h"
#include "food.h"

class GameManager: public QGraphicsView
{
    Q_OBJECT

public:
    GameManager(QWidget* parent=NULL);

    void mainMenuDisplay();
    void pauseMenuDisplay();
    void checkCollision();
    void endMenuDisplay(bool);
    void hudLoad();
    void environmentUI();
    void changeScoreHUD();
    void changeLivesHUD();
    void gameLoop();
    bool gameOver();
    QGraphicsScene* scene;
    QGraphicsScene* scenePause;
    QGraphicsScene* sceneGame;
    QGraphicsScene* sceneEnd;
    QGraphicsTextItem* scoreText;
    QGraphicsTextItem* livesText;
    QImage* map;
    QGraphicsPixmapItem* item;

    Environment* environment;

    std::list<Character*> characters;
    std::list<Item*> items;

    Player* player; //needs scene to load itself and progress itself?
    Enemy* ghost1;
    Enemy* ghost2;
    Enemy* ghost3;
    Enemy* ghost4;

    void initItems();
    void displayItems();
    void hitItems();
    bool goldRemaining();

    int i;

    bool isPlaying;

public slots:
    void newGame();
    void quitGame();
    void pauseGame();
    void resumeGame();
    void goMainMenu();
    void keyPressEvent(QKeyEvent *event);
};
