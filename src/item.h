#ifndef ITEM_H
#define ITEM_H

#include "character.h"

class Item : public Character {
public:
    Item(int x, int y);
    ~Item();

    bool isHitByPlayer();
    void move();
    void place();
};


#endif // ITEM_H
