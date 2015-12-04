#include "AI.h"

AI::AI()
{
    for(int row=0;row<rownum;row++)
    {for(int col=0;col<rownum;col++)
        {
         loc[row][col].piece=2;//默认空
         loc[row][col].row=row;
         loc[row][col].row=col;
        }
    }

    _sideofAI=false;


}

void AI::init()
{
    for(int row=0;row<rownum;row++)
    {for(int col=0;col<rownum;col++)
        {
         setLoc(row,col,2);
        }
    }
}

void AI::setLoc(int row, int col, char piece)
{
    loc[row][col].piece=piece;
}

Loc AI::analyse()
{


    int maxPlayerCore=0,maxAICore=0,tmpPlayerCore=0,tmpAICore=0;
    Loc player,ai;
     //棋盘满时则返回不存在的（rownum,rownum）位置
    player={rownum,rownum,0};
    ai={rownum,rownum,0};




    for(int row=0;row<rownum;row++)
    {for(int col=0;col<rownum;col++)
        {
            if(loc[row][col].piece==2)
            {
               tmpPlayerCore=getCore(row,col,_sideofAI);
               if(tmpPlayerCore>=maxPlayerCore)
               {maxPlayerCore=tmpPlayerCore;
               player.row=row;
               player.col=col;
               }
               tmpAICore=getCore(row,col,!_sideofAI);
               if(tmpAICore>=maxAICore)
               {maxAICore=tmpAICore;
               ai.row=row;
               ai.col=col;
               }
            }
        }
    }

    if(maxPlayerCore>=maxAICore)
    {
        return player;
    }
    else
    {
        return ai;
    }
}
bool AI::getSideofAI() const
{
    return _sideofAI;
}

void AI::setSideofAI(bool sideofAI)
{
    _sideofAI = sideofAI;
}


int AI::getCore(int row, int col, bool side)
{


    int tmpCore=0,sumCore=0;
    int boundstate[2];//[0]:连线头端有无子 [1]:连线末端有无子
    int num;




    //横向
    boundstate[0]=1;boundstate[1]=1;
    num=0;
    //向右

    for(int k=1;k<rownum-col;k++)
    {
        if(loc[row][col+k].piece==side)
        {num++;
        continue;
        }
        if(loc[row][col+k].piece==2)
        {
            boundstate[1]=0;
            break;
        }
        if(loc[row][col+k].piece==(!side))
        {
            boundstate[1]=1;
            break;
        }
    }
    //向左
    for(int k=1;k<=col;k++)
    {
        if(loc[row][col-k].piece==side)
        {num++;
        continue;
        }
        if(loc[row][col-k].piece==2)
        {
            boundstate[0]=0;
            break;
        }
        if(loc[row][col-k].piece==(!side))
        {
            boundstate[0]=1;
            break;
        }
    }


     //调用评分函数
    tmpCore = evaluate(num,boundstate);
    sumCore += tmpCore;



    //纵向:
    boundstate[0]=1;boundstate[1]=1;
    num=0;
    //向下
    for(int k=1;k<rownum-row;k++)
    {
        if(loc[row+k][col].piece==side)
        {num++;
        continue;
        }
        if(loc[row+k][col].piece==2)
        {
            boundstate[1]=0;
            break;
        }
        if(loc[row+k][col].piece==(!side))
        {
            boundstate[1]=1;
            break;
        }
    }
    //向上
    for(int k=1;k<=row;k++)
    {
        if(loc[row-k][col].piece==side)
        {num++;
        continue;
        }
        if(loc[row-k][col].piece==2)
        {
            boundstate[0]=0;
            break;
        }
        if(loc[row-k][col].piece==(!side))
        {
            boundstate[0]=1;
            break;
        }
    }
    tmpCore = evaluate(num,boundstate);
    sumCore += tmpCore;

    //从左上到右下
    boundstate[0]=1;boundstate[1]=1;
    num=0;
    //下
    for(int k=1;k<rownum-row&&k<rownum-col;k++)//to do
    {
        if(loc[row+k][col+k].piece==side)
        {num++;
        continue;
        }
        if(loc[row+k][col+k].piece==2)
        {
            boundstate[1]=0;
            break;
        }
        if(loc[row+k][col+k].piece==(!side))
        {
            boundstate[1]=1;
            break;
        }
    }
    //上
    for(int k=1;k<=row&&k<=col;k++)
    {
        if(loc[row-k][col-k].piece==side)
        {num++;
        continue;
        }
        if(loc[row-k][col-k].piece==2)
        {
            boundstate[0]=0;
            break;
        }
        if(loc[row-k][col-k].piece==(!side))
        {
            boundstate[0]=1;
            break;
        }
    }
    tmpCore = evaluate(num,boundstate);
    sumCore += tmpCore;

    //从右上到左下
    boundstate[0]=1;boundstate[1]=1;
    num=0;
    //下
    for(int k=1;k<rownum-row&&k<=col;k++)//to do
    {
        if(loc[row+k][col-k].piece==side)
        {num++;
        continue;
        }
        if(loc[row+k][col-k].piece==2)
        {
            boundstate[1]=0;
            break;
        }
        if(loc[row+k][col-k].piece==(!side))
        {
            boundstate[1]=1;
            break;
        }
    }
    //上
    for(int k=1;k<=row&&k<rownum-col;k++)
    {
        if(loc[row-k][col+k].piece==side)
        {num++;
        continue;
        }
        if(loc[row-k][col+k].piece==2)
        {
            boundstate[0]=0;
            break;
        }
        if(loc[row-k][col+k].piece==(!side))
        {
            boundstate[0]=1;
            break;
        }
    }
    tmpCore = evaluate(num,boundstate);
    sumCore += tmpCore;


    return sumCore;
}

int AI::evaluate(int num,int bp[])//need change name
{
    int max = 0;
        if (num >= 4)
        {
            max += 10000; //成五
        }
        else if (num == 3)
        {
            if (bp[1] == 1 && bp[0] == 1) //不成五
            {
                max += 0;
            }
            else if (bp[1] == 0 && bp[0] == 0) //活四
            {
                max += 3000;
            }
            else
            {
                max += 900; //冲四
            }
        }
        else if (num == 2)
        {
            if (bp[0] == 0 && bp[1] == 0)
            {
                max += 460; //活三
            }
            else if (bp[0] == 1 && bp[1] == 1)
            {
                max += 0; //不成五
            }
            else
            {
                max += 30; //死三
            }
        }
        else if (num == 1)
        {
            if (bp[0] == 0 && bp[1] == 0)
            {
                max += 45;  //活二
            }
            else if (bp[0] == 1 && bp[1] == 1)
            {
                max += 0;
            }
            else
            {
                max += 5;
            }
        }
        else if (num == 0)
        {
            if (bp[0] == 0 && bp[1] == 0)
            {
                max += 3;
            }
            else if (bp[0] == 1 && bp[1] == 1)
            {
                max += 0;
            }
            else
            {
                max += 1;
            }
        }
        return max;
}

