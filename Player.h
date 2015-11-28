#ifndef PLAYER_H
#define PLAYER_H
#include<cstdint>
#include"ChessBoard.h"
struct loc
{
    size_t row;
    size_t col;
};

class Player
{
public:
    Player();
    Player(bool isBlack);
    virtual void play();

    loc lastpieceloc() const;
    void setLastpieceloc(const loc &lastpieceloc);

protected:
    bool _isBlack;//是黑方？
    loc _lastpieceloc;//当前该玩家最后一手棋的位置
};

#endif // PLAYER_H
