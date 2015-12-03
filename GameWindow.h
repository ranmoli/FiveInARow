#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include"Player.h"
#include<QtCore>

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    GameWindow(QWidget *parent = 0,bool isPVP=true);
    ~GameWindow();

private:
    Ui::GameWindow *ui;

private slots:


    void on_restartButton_clicked();
    void on_backButton_clicked();
};

#endif // GAMEWINDOW_H
