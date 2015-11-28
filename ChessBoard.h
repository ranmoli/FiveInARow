#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QFrame>
#include<QEvent>
#include<QPainter>
#include"Piece.h"

extern const double pieceradius;//棋子半径
const size_t rowgridnum =15;//每行格点数

struct Location
{
    QPoint point;
    bool isLocated;
    Piece piece;
};

class ChessBoard : public QFrame//黑白棋棋盘
{
    Q_OBJECT
public:
    explicit ChessBoard(QWidget *parent = 0);

    void drawBoard();
    void drawPiece(size_t row,size_t col,bool isBlack);
    void cleanPiece(size_t row,size_t col);
    void cleanAllPeices();

protected:
    void paintEvent(QPaintEvent *event);

protected:
    double _boardlength,_boardwidth;//棋盘自身长宽
    QPoint _originalpoint;//栅格原点
    double _gridsidelength;//格宽
    Location _location[rowgridnum][rowgridnum];

protected:

};

#endif // CHESSBOARD_H
