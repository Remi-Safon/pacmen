#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include "character.h"
#include <vector.h>


class Player : public Character {
private:
    int lives;
    Qt::Key nextMove;

public:
    Player(int x, int y);
    ~Player();

    // override functions
    void move();


    int loseLive();
    void setNextMove(Qt::Key nextMove);
    bool isAlive();
};

#endif // PLAYER_H
