#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include"Rule.h"
#include<QtCore>

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::GameWindow *ui;

protected:
    bool currentplayer;//true:is black false:is white
};

#endif // GAMEWINDOW_H
