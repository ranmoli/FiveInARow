#ifndef AI_H
#define AI_H

#include<QtCore>//for testing
const int rownum=15;

struct Loc
{
    int row;
    int col;
    char piece;//0:white 1:black 2:nothing
};

class AI
{
public:
    AI();
    void init();
    void setLoc(int row,int col,char piece);
    Loc analyse();

    bool getSideofAI() const;
    void setSideofAI(bool sideofAI);

protected:
    Loc loc[rownum][rownum];
    bool _sideofAI;//true:black false:white
    int getCore(int row,int col,bool side);
    int evaluate(int num,int boundstate[]);
};

#endif // AI_H
