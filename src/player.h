#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include "character.h"
#include <vector.h>


class Player : public Character {
private:
    int lives;
    Qt::Key nextMove;
    void checkEat();

public:
    Player(int x, int y);
    ~Player();

    // override functions
    void move();

    int nbGold;
    bool ghostEater;
    void canEatGhost();
    int loseLive();
    void setNextMove(Qt::Key nextMove);
    bool isAlive();
    int getLives();
};
