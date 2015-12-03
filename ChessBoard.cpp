#include "ChessBoard.h"

ChessBoard::ChessBoard(QWidget *parent) : QFrame(parent)
{
_boardlength=pieceradius*2*rowgridnum;
_boardwidth=pieceradius*2*rowgridnum;
_originalpoint=QPoint(pieceradius,pieceradius);
_gridsidelength=pieceradius*2;
_sidelength=_gridsidelength*(rowgridnum-1);

_currentplayer=true;//black

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

    painter.setBrush(Qt::black);
    painter.drawEllipse(QPoint(_originalpoint.x()+_gridsidelength*3,_originalpoint.y()+_gridsidelength*3),3,3);//左上星
    painter.drawEllipse(QPoint(_originalpoint.x()+_sidelength-_gridsidelength*3,_originalpoint.y()+_gridsidelength*3),3,3);//右上星
    painter.drawEllipse(QPoint(_originalpoint.x()+_gridsidelength*3,_originalpoint.y()+_sidelength-_gridsidelength*3),3,3);//左下星
    painter.drawEllipse(QPoint(_originalpoint.x()+_sidelength-_gridsidelength*3,_originalpoint.y()+_sidelength-_gridsidelength*3),3,3);//右下星
    painter.drawEllipse(QPoint(_originalpoint.x()+_gridsidelength*(rowgridnum-1)/2,_originalpoint.y()+_gridsidelength*(rowgridnum-1)/2),3,3);//天元
    painter.setBrush(Qt::NoBrush);

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

void ChessBoard::mousePressEvent(QMouseEvent *event)
{

 if(isPVP())
 {
    int row=static_cast<size_t>(event->y()/_gridsidelength),col=static_cast<size_t>(event->x()/_gridsidelength);
    if(!isLocatedPiece(row,col))
    {
        drawPiece(row,col,_currentplayer);
        update();
    }

    if(isFiveInARow(row,col))
    {
        if(_currentplayer)
        {
            QMessageBox::information(this,tr("BLACK WIN!"),tr("BLACK WIN!"),QMessageBox::Ok);
        }
        else
        {
            QMessageBox::information(this,tr("WHITE WIN!"),tr("WHITE WIN!"),QMessageBox::Ok);
        }
        init();
        return;
    }
    _currentplayer =!_currentplayer;
 }
 else
 {
    //PVE condition
 }

}
bool ChessBoard::isPVP() const
{
    return _isPVP;
}

void ChessBoard::setIsPVP(bool isPVP)
{
    _isPVP = isPVP;
}


bool ChessBoard::currentplayer() const
{
    return _currentplayer;
}

void ChessBoard::setCurrentplayer(bool currentplayer)
{
    _currentplayer = currentplayer;
}

void ChessBoard::init()
{
    cleanAllPeices();
    setCurrentplayer(true);
}

bool ChessBoard::isFiveInARow(size_t row,size_t col)
{
    if(!isLocatedPiece(row,col)){return false;}


    int counter=1;
    for(size_t i=row+1;i<rowgridnum;i++)//向下
    {
        if(isLocatedPiece(i,col))
        {
            if(isBlackPiece(row,col)==isBlackPiece(i,col))
            {counter++;}
            else{break;}
        }
        else{break;}
    }
    for(int i=row-1;i>=0;i--)//向上
    {
        if(isLocatedPiece(i,col))
        {
            if(isBlackPiece(row,col)==isBlackPiece(i,col))
            {counter++;}
            else{break;}
        }
        else{break;}
    }
    if(counter>=5){return true;}
    //判断纵向

    counter=1;
    for(size_t i=col+1;i<rowgridnum;i++)//向右
    {
        if(isLocatedPiece(row,i))
        {
            if(isBlackPiece(row,col)==isBlackPiece(row,i))
            {counter++;}
            else{break;}
        }
        else{break;}
    }
    for(int i=col-1;i>=0;i--)//向左
    {
        if(isLocatedPiece(row,i))
        {
            if(isBlackPiece(row,col)==isBlackPiece(row,i))
            {counter++;}
            else{break;}
        }
        else{break;}
    }
    if(counter>=5){return true;}
    //判断横向

    counter=1;
    for(size_t i=row+1,j=col+1;i<rowgridnum&&j<rowgridnum;i++,j++)
    {
        if(isLocatedPiece(i,j))
        {
            if(isBlackPiece(row,col)==isBlackPiece(i,j))
            {counter++;}
            else{break;}
        }
        else{break;}
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
    {
        if(isLocatedPiece(i,j))
        {
            if(isBlackPiece(row,col)==isBlackPiece(i,j))
            {counter++;}
            else{break;}
        }
        else{break;}
    }
    if(counter>=5){return true;}
    //判断斜下

    counter=1;
    for(int i=row-1,j=col+1;i>=0&&j<rowgridnum;i--,j++)
    {
        if(isLocatedPiece(i,j))
        {
            if(isBlackPiece(row,col)==isBlackPiece(i,j))
            {counter++;}
            else{break;}
        }
        else{break;}
    }
    for(int i=row+1,j=col-1;i<rowgridnum&&j>=0;i++,j--)
    {
        if(isLocatedPiece(i,j))
        {
            if(isBlackPiece(row,col)==isBlackPiece(i,j))
            {counter++;}
            else{break;}
        }
        else{break;}
    }
    if(counter>=5){return true;}
    //判断斜上


    return false;
}




