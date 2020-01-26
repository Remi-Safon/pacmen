#pragma once

#include "character.h"

class Enemy : public Character
{
public:
    Enemy(int x, int y);
    ~Enemy();

    // override functions
    void move();

};
