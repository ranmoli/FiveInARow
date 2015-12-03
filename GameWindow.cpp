#include "GameWindow.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("FiveInARow"));
    setStyleSheet("background-color:rgb(219,207,202)");
    setFixedSize(770,620);

}

GameWindow::GameWindow(QWidget *parent, bool isPVP):
QDialog(parent),
ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("FiveInARow"));
    setStyleSheet("background-color:rgb(219,207,202)");
    setFixedSize(770,620);

    ui->chessboard->setIsPVP(isPVP);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_restartButton_clicked()
{
    //1.判断棋盘是否有子，有子则提示存盘
    ui->chessboard->init();
}

void GameWindow::on_backButton_clicked()
{
    QWidget::close();
}
