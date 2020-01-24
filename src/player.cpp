#include "player.h"

Player::Player(int x, int y) : Character(x, y)
{
    lives = 3;
}
Player::~Player() {
}

int Player::loseLive()
{
    return lives--;
}
void Player::move() {
}
