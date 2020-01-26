#include "player.h"

Player::Player(int x, int y) : Character(x, y) {
    lives = 3;
    nbGold = 0;
    ghostEater = false;
    this->nextMove = Qt::Key_0;
    this->characterType = BoxState::PLAYER;
    this->environment->setStateBox(x, y, BoxState::PLAYER);
}
Player::~Player() {
}

int Player::loseLive() {
    return lives--;
}
void Player::move() {

    this->oldBoardPos->set(this->boardPos->x, this->boardPos->y);

    std::map<Qt::Key, BoxState> possibleMoves;
    possibleMoves[Qt::Key_Up] = this->environment->getBoxState(this->boardPos->x, this->boardPos->y - 1);
    possibleMoves[Qt::Key_Down] = this->environment->getBoxState(this->boardPos->x, this->boardPos->y + 1);
    possibleMoves[Qt::Key_Right] = this->environment->getBoxState(this->boardPos->x + 1, this->boardPos->y);
    possibleMoves[Qt::Key_Left] = this->environment->getBoxState(this->boardPos->x - 1, this->boardPos->y);


   if (this->nextMove != Qt::Key_0 && possibleMoves[this->nextMove] != BoxState::WALL) {
       this->boardPos->add (
                   this->movesVector.at(this->nextMove).x,
                   this->movesVector.at(this->nextMove).y
       );
       this->lastMove = this->nextMove;
   } else if (this->lastMove != Qt::Key_0 && possibleMoves[this->lastMove] != BoxState::WALL) {
       this->boardPos->add (
                   this->movesVector.at(this->lastMove).x,
                   this->movesVector.at(this->lastMove).y
       );
   } else {/*
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

       this->boardPos->add (
                   this->movesVector.at(leftPossibilities[rand]).x,
                   this->movesVector.at(leftPossibilities[rand]).y
       );
       this->lastMove = leftPossibilities[rand];
*/
   }
   this->checkEat();
   this->environment->setStateBox(this->boardPos->x, this->boardPos->y, BoxState::PLAYER);
   this->nextMove = Qt::Key_0;
   possibleMoves.clear();
}

void Player::setNextMove(Qt::Key nextMove) {
    this->nextMove = nextMove;
    switch (this->nextMove) {
        case Qt::Key_Up:
            qDebug("UP");
        break;
        case Qt::Key_Down:
            qDebug("DOWN");
        break;
        case Qt::Key_Left:
            qDebug("LEFT");
        break;
        case Qt::Key_Right:
            qDebug("RIGHT");
        break;
    }

}

bool Player::isAlive() {
    return this->lives > 0;
}
int Player::getLives() {
    return this->lives;
}
void Player::checkEat() {
    if (this->environment->getBoxState(this->boardPos->x, this->boardPos->y) == BoxState::GOLD) {
        this->nbGold++;
    }
}
void Player::canEatGhost() {
    ghostEater = true;
}
