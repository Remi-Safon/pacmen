#include "item.h"

Item::Item(int x, int y) : Character(x, y) {
    this->environment->setStateBox(x, y, BoxState::GOLD); // ennemy placement on the board
    this->characterType = BoxState::GOLD;
}

Item::~Item() {
}


void Item::move() {}

bool Item::isHitByPlayer() {
    if (this->environment->getBoxState(
                this->boardPos->x,
                this->boardPos->y
                ) == BoxState::PLAYER) {
        return true;
    }
    return false;
}
void Item::place() {
    this->environment->setStateBox(this->boardPos->x, this->boardPos->y, this->characterType);
}



