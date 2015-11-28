#include "Rule.h"

Rule::Rule()
{

}

bool Rule::isPlayerWin(ChessBoard *chessboard)
{
  size_t counter;

  for(size_t row=0;row<rowgridnum;row++)//判断横行是否有五连珠
  {   counter=0;

      for(size_t col=0;col<rowgridnum;col++)
      {
          if(chessboard->isLocatedPiece(row,col)&&((col+1)!=rowgridnum))
          {

              if(chessboard->isLocatedPiece(row,col+1))
              {
                  if(chessboard->isBlackPiece(row,col)==chessboard->isBlackPiece(row,col+1))
                  {counter++;}
                  else{counter=0;}
              }
          }
      }
      if(counter==4){return true;}
  }

  for(size_t col=0;col<rowgridnum;col++)//判断纵行是否有五连珠
  {
      counter=0;
      for(size_t row=0;row<rowgridnum;row++)
      {
          if(chessboard->isLocatedPiece(row,col)&&((row+1)!=rowgridnum))
          {
              if(chessboard->isBlackPiece(row,col)==chessboard->isBlackPiece(row+1,col))
              {counter++;}
              else{counter=0;}
          }
      }
      if(counter==4){return true;}
  }

  for(size_t r=0;r<rowgridnum;r++)//判断右斜上是否有五连珠
  {
      counter=0;
      for(int row=r,col=0;row>=0&&col<rowgridnum;row--,col++)//int
      {
          if(chessboard->isLocatedPiece(row,col)&&((col+1)!=rowgridnum)&&((row-1)>=0))
          {
              if(chessboard->isBlackPiece(row,col)==chessboard->isBlackPiece(row-1,col+1))
              {counter++;}
              else{counter=0;}
          }
      }
      if(counter==4){return true;}
  }

  for(size_t r=0;r<rowgridnum;r++)//判断左斜上是否有五连珠
  {
      counter=0;
      for(int row=r,col=rowgridnum-1;row>=0&&col>=0;row--,col--)
      {
        if(chessboard->isLocatedPiece(row,col)&&((col-1)>=0)&&((row-1)>=0))
        {
            if(chessboard->isBlackPiece(row,col)==chessboard->isBlackPiece(row-1,col-1))
            {counter++;}
            else{counter=0;}
        }
      }
      if(counter==4){return true;}
  }

  //to do

  return false;
}

