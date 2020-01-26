#include "character.h"

Character::Character (int x, int y) {

    this->boardPos = new Vector(x,y);
    this->oldBoardPos = new Vector(x,y);
    this->environment = BoardService::getInstance();
    this->lastMove = Qt::Key_0;

    this->movesVector[Qt::Key_Up] = *new Vector(0, -1);
    this->movesVector[Qt::Key_Down] = *new Vector(0, 1);
    this->movesVector[Qt::Key_Left] = *new Vector(-1, 0);
    this->movesVector[Qt::Key_Right] = *new Vector(1, 0);
}
Character::~Character () {
}

bool Character::isCollision(Character* c) {

    if (this->characterType != c->characterType) {
        if (
                *(this->boardPos) == *(c->boardPos)
                || (
                    *(this->boardPos) == *(c->oldBoardPos)
                    && *(this->oldBoardPos) == *(c->boardPos)
                    )
         ) {
            return true;
        }
    }
    return false;

}
