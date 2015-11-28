#include "Player.h"

Player::Player()
{
    _isBlack=true;
}

Player::Player(bool isBlack)
{
    _isBlack=isBlack;
}

void Player::play()
{
    //to do
}
loc Player::lastpieceloc() const
{
    return _lastpieceloc;
}

void Player::setLastpieceloc(const loc &lastpieceloc)
{
    _lastpieceloc = lastpieceloc;
}


