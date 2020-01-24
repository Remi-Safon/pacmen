#include "player.h"

Player::Player(int x, int y) : Character(x, y) {
    lives = 3;
}
Player::~Player() {
}

int Player::loseLive() {
    return lives--;
}
void Player::move() {

    switch (this->nextMove) {
        case Qt::Key_Up:
            qDebug ("UP\n");
        break;

        case Qt::Key_Down:
            qDebug ("DOWN\n");
        break;

        case Qt::Key_Left:
            qDebug ("LEFT\n");
        break;

        case Qt::Key_Right:
            qDebug ("RIGHT\n");
        break;
    }
}

void Player::setNextMove(Qt::Key nextMove) {
    this->nextMove = nextMove;
}
