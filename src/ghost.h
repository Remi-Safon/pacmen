#ifndef GHOST_H
#define GHOST_H

#include "enemy.h"

class Ghost : public Enemy
{
public:
    Ghost(int x, int y);
    ~Ghost();

    // override functions
    void move();

};
#endif // GHOST_H
