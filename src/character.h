#ifndef CHARACTER_H
#define CHARACTER_H

#include "environment.h"
#include "boardservice.h"

class Character {

private :
    Environment* environment;
    int boardPositionX;
    int boardPositionY;

public :
    Character(int x, int y);
    virtual ~Character();
    virtual void move() = 0;
};



#endif // CHARACTER_H
