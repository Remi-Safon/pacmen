#ifndef BOXSTATE_H
#define BOXSTATE_H


enum class  BoxState {
    FREE = 0,
    WALL = 1,
    PLAYER = 2,
    ENEMY = 3,
    FOOD = 4,
    GOLD = 5,
    EMPTY = 6
};

#endif // BOXSTATE_H
