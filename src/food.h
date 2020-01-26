#ifndef FOOD_H
#define FOOD_H

#include "item.h"

class Food : public Item {
public:
    Food(int x, int y);

    ~Food();
};

#endif // FOOD_H
