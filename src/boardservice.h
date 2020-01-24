#ifndef BOARDSERVICE_H
#define BOARDSERVICE_H

#include "environment.h"

class BoardService {

private:
    static Environment* instance;

public:
    static Environment* getInstance();

};



#endif // BOARDSERVICE_H
