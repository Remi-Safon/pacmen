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
#include <QImage>
#include <cstdlib>
#include <iostream>
#include <ctime>

#include <boxstate.h>
#include "vector.h"

#define BOARD_X 19
#define BOARD_Y 29
#define NB_BOARDS 2


using namespace std;



class Environment {
public:
    BoxState board [BOARD_Y][BOARD_X];
    int animIndex = 0;
    int indexBoard;
    string toString();
    Environment();
    void setStateBox(int x, int y, BoxState state);
    BoxState getBoxState(int x, int y);
    void init();
    void initGold();
    QImage display();
    int boardSizeX;
    int boardSizeY;
    Vector Environment::getPlayerPos();
};

#endif // ENVIRONMENT_H
