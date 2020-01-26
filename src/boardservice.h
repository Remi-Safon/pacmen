#pragma once

#include "environment.h"

class BoardService
{
public:
    static Environment* getInstance();

private:
    static Environment* instance;
};
