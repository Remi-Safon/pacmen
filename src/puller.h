#ifndef PULLER_H
#define PULLER_H


#include "enemy.h"

class Puller : public Enemy
{
public:
    Puller(int x, int y);
    ~Puller();



    // override functions
    void move();

};

#endif // PULLER_H
