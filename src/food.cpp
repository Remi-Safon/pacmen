#include "food.h"


Food::Food(int x, int y) : Item(x, y) {
    this->environment->setStateBox(x, y, BoxState::FOOD); // ennemy placement on the board
    this->characterType = BoxState::FOOD;
}

Food::~Food() {
}
