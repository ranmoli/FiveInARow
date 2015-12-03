#include "MenuWindow.h"
#include "ui_MenuWindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    setFixedSize(160,200);
    setWindowFlags(Qt::FramelessWindowHint);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_PVPButton_clicked()
{
    GameWindow* gamewindow=new GameWindow(this,true);
    gamewindow->setAttribute(Qt::WA_ShowModal,true);
    gamewindow->show();
}

void MenuWindow::on_exitButton_clicked()
{
    QApplication::exit();
}

void MenuWindow::on_PVEButton_clicked()
{
    GameWindow* gamewindow=new GameWindow(this,false);
    gamewindow->setAttribute(Qt::WA_ShowModal,true);
    gamewindow->show();
}
