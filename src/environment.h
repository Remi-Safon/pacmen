#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

// constructing vectors
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <QDebug>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define BOARD_X 19
#define BOARD_Y 29
#define NB_BOARDS 2


using namespace std;

enum class  BoxState {
    FREE = 0,
    WALL = 1,
    PLAYER = 2,
    ENNEMIES = 3,
    FOOD = 4
};



class Environment {
public:
    BoxState board [BOARD_Y][BOARD_X];

    Environment();
    string toString();
};

#endif // ENVIRONMENT_H
