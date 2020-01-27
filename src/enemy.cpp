#include "enemy.h"

Enemy::Enemy(int x, int y) : Character(x, y) {
    this->environment->setStateBox(x, y, BoxState::ENEMY); // ennemy placement on the board
    this->characterType = BoxState::ENEMY;
    std::srand(std::time(NULL));
}

Enemy::~Enemy() {
}


