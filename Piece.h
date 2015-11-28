#ifndef PIECE_H
#define PIECE_H

const double pieceradius = 20;

class Piece//黑白棋子类
{
public:
    Piece();
    Piece(double radius,bool isBlack);
    double radius() const;
    void setRadius(double radius);

    bool isBlack() const;
    void setIsBlack(bool isBlack);

protected:
    double _radius;
    bool _isBlack;
};

#endif // PIECE_H
