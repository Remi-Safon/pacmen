
#include "gold.h"

Gold::Gold(int x, int y) : Item(x, y) {
    this->environment->setStateBox(x, y, BoxState::GOLD); // ennemy placement on the board
    this->characterType = BoxState::GOLD;
}

Gold::~Gold() {
}
