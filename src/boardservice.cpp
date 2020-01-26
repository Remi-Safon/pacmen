#include "boardservice.h"

Environment* BoardService::instance = 0;

Environment* BoardService::getInstance()
{
    if (instance == 0) {
        instance = new Environment();
    }

    return instance;
}
