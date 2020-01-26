#ifndef CHARACTER_H
#define CHARACTER_H

#include "environment.h"
#include "boardservice.h"
#include "boxstate.h"
#include <map>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "vector.h"
#include <time.h>
#include <vector>

class Character {

private :


public :
    Character(int x, int y);
    virtual ~Character();
    virtual void move() = 0;
    BoxState characterType;
    bool isCollision(Character*);

protected :
    Environment* environment;
    std::map<Qt::Key, Vector> movesVector;
    Qt::Key lastMove;
/*
    int boardPositionX;
    int boardPositionY;
*/

    Vector* boardPos;
    Vector* oldBoardPos;
};



#endif // CHARACTER_H
