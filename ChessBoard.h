#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QFrame>
#include<QEvent>
#include<QPainter>
#include<QtCore>
#include"Piece.h"

extern const double pieceradius;//棋子半径
const size_t rowgridnum =15;//每行格点数
//棋盘大小网格数由以上两参数完全决定


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

    void drawPiece(size_t row,size_t col,bool isBlack);//不检查是否有子，使用前需先判断
    void cleanPiece(size_t row,size_t col);
    void cleanAllPeices();
    bool isLocatedPiece(size_t row,size_t col);
    bool isBlackPiece(size_t row,size_t col);//不检查是否有子，使用前需先判断
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
