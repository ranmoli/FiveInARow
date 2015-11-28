#include "Piece.h"

Piece::Piece()
{
    _radius=18;
    _isBlack=true;
}

Piece::Piece(double radius, bool isBlack)
{
    _radius=radius;
    _isBlack=isBlack;
}
double Piece::radius() const
{
    return _radius;
}

void Piece::setRadius(double radius)
{
    _radius = radius;
}
bool Piece::isBlack() const
{
    return _isBlack;
}

void Piece::setIsBlack(bool isBlack)
{
    _isBlack = isBlack;
}



