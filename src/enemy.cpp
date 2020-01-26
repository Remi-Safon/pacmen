#include "enemy.h"

Enemy::Enemy(int x, int y) : Character(x, y) {
    this->environment->setStateBox(x, y, BoxState::ENEMY); // ennemy placement on the board
    std::srand(std::time(NULL));
}

Enemy::~Enemy() {
}


void Enemy::move() {

    std::map<Qt::Key, BoxState> possibleMoves;
    possibleMoves[Qt::Key_Up] = this->environment->getBoxState(this->boardPositionX, this->boardPositionY - 1);
    possibleMoves[Qt::Key_Down] = this->environment->getBoxState(this->boardPositionX, this->boardPositionY + 1);
    possibleMoves[Qt::Key_Right] = this->environment->getBoxState(this->boardPositionX + 1, this->boardPositionY);
    possibleMoves[Qt::Key_Left] = this->environment->getBoxState(this->boardPositionX - 1, this->boardPositionY);

    switch (this->lastMove) {
        case Qt::Key_Up:
            possibleMoves.erase(Qt::Key_Down);
        break;
        case Qt::Key_Down:
            possibleMoves.erase(Qt::Key_Up);
        break;
        case Qt::Key_Left:
            possibleMoves.erase(Qt::Key_Right);
        break;
        case Qt::Key_Right:
            possibleMoves.erase(Qt::Key_Left);
        break;
    }

    std::vector<Qt::Key> leftPossibilities;

    for (map<Qt::Key, BoxState>::iterator it = possibleMoves.begin(); it != possibleMoves.end(); it++) {
        if (it->second != BoxState::WALL) {
            leftPossibilities.push_back(it->first);
        }

    }

    unsigned int rand = std::rand() % leftPossibilities.size();
    this->boardPositionX += this->movesVector.at(leftPossibilities[rand]).x;
    this->boardPositionY += this->movesVector.at(leftPossibilities[rand]).y;
    this->lastMove = leftPossibilities[rand];
    this->environment->setStateBox(this->boardPositionX, this->boardPositionY, BoxState::ENEMY);

    possibleMoves.clear();
}

