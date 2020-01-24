#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"

class Enemy : public Character
{
public:
    Enemy(int x, int y);
    ~Enemy();

    // override functions
    void move();
};

#endif // ENEMY_H
