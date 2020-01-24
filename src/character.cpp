#include "character.h"

Character::Character (int x, int y) {
    this->boardPositionX = x;
    this->boardPositionY = y;
}
Character::~Character () {
    this->environment = BoardService::getInstance();
}
