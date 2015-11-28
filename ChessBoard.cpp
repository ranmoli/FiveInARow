#include "ChessBoard.h"

ChessBoard::ChessBoard(QWidget *parent) : QFrame(parent)
{
_boardlength=pieceradius*2*rowgridnum;
_boardwidth=pieceradius*2*rowgridnum;
_originalpoint=QPoint(pieceradius,pieceradius);
_gridsidelength=pieceradius*2;

for(size_t row=0;row<rowgridnum;row++)//初始化位置管理器_location
{
    for(size_t col=0;col<rowgridnum;col++)
    {
        _location[row][col].point=QPoint(_originalpoint.x()+col*_gridsidelength,_originalpoint.y()+row*_gridsidelength);
        _location[row][col].isLocated=false;
    }
}

setFixedSize(_boardlength,_boardwidth);
setStyleSheet("background-color:rgb(166,137,124)");

update();
}

void ChessBoard::drawPiece(size_t row, size_t col, bool isBlack)
{
 _location[row][col].isLocated=true;
 if(isBlack){_location[row][col].piece.setIsBlack(true);}
 else{_location[row][col].piece.setIsBlack(false);}
 update();
}

void ChessBoard::cleanPiece(size_t row, size_t col)//need testing
{
    _location[row][col].isLocated=false;
    update();
}

void ChessBoard::cleanAllPeices()//need testing
{
    for(size_t row=0;row<rowgridnum;row++)
    {
        for(size_t col=0;col<rowgridnum;col++)
        {
            cleanPiece(row,col);
        }
    }
    update();
}

bool ChessBoard::isLocatedPiece(size_t row, size_t col)
{
    return _location[row][col].isLocated;
}

bool ChessBoard::isBlackPiece(size_t row, size_t col)
{
    return _location[row][col].piece.isBlack();
}

void ChessBoard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(size_t i=0;i<rowgridnum;i++)//绘制纵线
    {painter.drawLine(QPoint(_originalpoint.x()+i*_gridsidelength,_originalpoint.y()),
                      QPoint(_originalpoint.x()+i*_gridsidelength,_originalpoint.y()+_gridsidelength*(rowgridnum-1)));
    }
    for(size_t i=0;i<rowgridnum;i++)//绘制横线
    {painter.drawLine(QPoint(_originalpoint.x(),_originalpoint.y()+i*_gridsidelength),
                      QPoint(_originalpoint.x()+_gridsidelength*(rowgridnum-1),_originalpoint.y()+i*_gridsidelength));
    }

    for(size_t row=0;row<rowgridnum;row++)//绘制棋子
    {
        for(size_t col=0;col<rowgridnum;col++)
        {
            if(_location[row][col].isLocated)
            {
                QPen pen;
                if(_location[row][col].piece.isBlack())
                {
                    pen.setBrush(Qt::black);painter.setBrush(Qt::black);
                }
                else{pen.setBrush(Qt::white);painter.setBrush(Qt::white);}
                painter.setPen(pen);
                painter.drawEllipse(_location[row][col].point,_location[row][col].piece.radius(),_location[row][col].piece.radius());
            }
        }
    }
}

