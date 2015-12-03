#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <GameWindow.h>
#include<QtCore>


namespace Ui {
class MenuWindow;
}

class MenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();

private slots:
    void on_PVPButton_clicked();

    void on_exitButton_clicked();

    void on_PVEButton_clicked();

private:
    Ui::MenuWindow *ui;
};

#endif // MENUWINDOW_H
