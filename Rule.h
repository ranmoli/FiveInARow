#ifndef RULE_H
#define RULE_H
#include"ChessBoard.h"

#include<QDebug>

class Rule
{
public:
    Rule();
    bool isPlayerWin(ChessBoard *chessboard);//true:is black win false:is white win
protected:
};

#endif // RULE_H
