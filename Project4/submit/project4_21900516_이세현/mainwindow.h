#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include "ingame.h"
#include "computer.h"
//#include "sever.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Multi_clicked();

    void on_Single_clicked();

    void on_IPGame_clicked();

    void Go_Title();

    void on_GoTitle_clicked();

    void on_GoTitle_2_clicked();

    void on_GoTitle_3_clicked();

    void on_GoTitle_4_clicked();

    void setting();

    void on_GameStart_clicked();

    void vs();

    void click();

//    int check_win(QString c);

    void game_win();

    void on_Reset_clicked();

    void on_Yes_clicked();

    void on_No_clicked();

    void on_GameStart_2_clicked();

    void computer_click(int k);

//    int com_rule();

    void on_GameStart_5_clicked();

private:
    Ui::MainWindow *ui;
    QToolButton *omook[15][15];
};
#endif // MAINWINDOW_H
