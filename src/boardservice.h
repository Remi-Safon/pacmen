#ifndef BOARDSERVICE_H
#define BOARDSERVICE_H

#include "environment.h"

class BoardService {

private:
    static Environment* instance;

public:
    static Environment* getInstance();
    static void resetInstance();

};




#endif // BOARDSERVICE_H
