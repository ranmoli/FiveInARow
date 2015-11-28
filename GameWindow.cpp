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

GameWindow::~GameWindow()
{
    delete ui;
}
