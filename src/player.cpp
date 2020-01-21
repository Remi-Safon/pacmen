#include "player.h"

Player::Player()
{
    lives = 3;
}

int Player::loseLive()
{
    return lives--;
}
