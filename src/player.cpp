#include "player.h"

Player::Player(int x, int y) : Character(x, y) {
    lives = 3;
    this->nextMove = Qt::Key_0;
    this->environment->setStateBox(x, y, BoxState::PLAYER);
}
Player::~Player() {
}

int Player::loseLive() {
    return lives--;
}
void Player::move() {

    std::map<Qt::Key, BoxState> possibleMoves;
    possibleMoves[Qt::Key_Up] = this->environment->getBoxState(this->boardPositionX, this->boardPositionY - 1);
    possibleMoves[Qt::Key_Down] = this->environment->getBoxState(this->boardPositionX, this->boardPositionY + 1);
    possibleMoves[Qt::Key_Right] = this->environment->getBoxState(this->boardPositionX + 1, this->boardPositionY);
    possibleMoves[Qt::Key_Left] = this->environment->getBoxState(this->boardPositionX - 1, this->boardPositionY);


   if (this->nextMove != Qt::Key_0 && possibleMoves[this->nextMove] != BoxState::WALL) {
       this->boardPositionX += this->movesVector.at(this->nextMove).x;
       this->boardPositionY += this->movesVector.at(this->nextMove).y;
       this->lastMove = this->nextMove;
   } else if (this->nextMove != Qt::Key_0 && possibleMoves[this->lastMove] != BoxState::WALL) {
       this->boardPositionX += this->movesVector.at(this->lastMove).x;
       this->boardPositionY += this->movesVector.at(this->lastMove).y;
   } else {
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
       qDebug("rand : %d", rand);
       this->boardPositionX += this->movesVector.at(leftPossibilities[rand]).x;
       this->boardPositionY += this->movesVector.at(leftPossibilities[rand]).y;
       this->lastMove = leftPossibilities[rand];

   }
   this->environment->setStateBox(this->boardPositionX, this->boardPositionY, BoxState::PLAYER);
   this->nextMove = Qt::Key_0;
   possibleMoves.clear();
}

void Player::setNextMove(Qt::Key nextMove) {
    this->nextMove = nextMove;
}

bool Player::isAlive() {
    return this->lives > 0;
}
