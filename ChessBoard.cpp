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
}

