#include "puller.h"
#include "enemy.h"

Puller::Puller(int x, int y) : Enemy(x, y) {
    this->environment->setStateBox(x, y, BoxState::ENEMY); // ennemy placement on the board
    this->characterType = BoxState::ENEMY;
}

Puller::~Puller() {
}


void Puller::move() {

    std::map<Qt::Key, BoxState> possibleMoves;
    possibleMoves[Qt::Key_Up] = this->environment->getBoxState(this->boardPos->x, this->boardPos->y - 1);
    possibleMoves[Qt::Key_Down] = this->environment->getBoxState(this->boardPos->x, this->boardPos->y + 1);
    possibleMoves[Qt::Key_Right] = this->environment->getBoxState(this->boardPos->x + 1, this->boardPos->y);
    possibleMoves[Qt::Key_Left] = this->environment->getBoxState(this->boardPos->x - 1, this->boardPos->y);

    std::vector<Qt::Key> leftPossibilities;

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


    for (map<Qt::Key, BoxState>::iterator it = possibleMoves.begin(); it != possibleMoves.end(); it++) {
        if (it->second != BoxState::WALL) {
            leftPossibilities.push_back(it->first);
        }

    }

    unsigned int rand = std::rand() % leftPossibilities.size();
    this->oldBoardPos->set(this->boardPos->x, this->boardPos->y);
    this->boardPos->add (
                this->movesVector.at(leftPossibilities[rand]).x,
                this->movesVector.at(leftPossibilities[rand]).y
    );


    /**************************/




    this->lastMove = leftPossibilities[rand];
    this->environment->setStateBox(this->boardPos->x, this->boardPos->y, BoxState::ENEMY);

    possibleMoves.clear();
}
