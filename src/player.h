#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"


class Player : public Character {

private:
    int lives;

public:
    Player(int x, int y);
    ~Player();


    // override functions
    void move();

    int loseLive();
};

#endif // PLAYER_H
