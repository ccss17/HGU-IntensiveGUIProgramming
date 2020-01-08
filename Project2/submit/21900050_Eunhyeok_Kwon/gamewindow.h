#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>  //The QMainWindow class provides a main application window
#include "connect-game.h"
#include <QString>
#include <QDebug>

#include <QPushButton>  // included for gameflow function

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }  // Ui::MainWindow, custom class declared inside namespace Ui
QT_END_NAMESPACE

class MainWindow : public QMainWindow   // MainWindow class inheirts QMainWindow, this is different from class defined in namespace "Ui"
{
    Q_OBJECT    // QObject macro required for sinal and slots
    Connect C; // declare tic-tac-toe game class
    QString first_player_stone = "X";
    QString second_player_stone = "O";
    bool game_over = false;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:     // assign private slots
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();

    void on_btn_reset_clicked();

public:
    void game_flow(int x, int y, QPushButton &ref);
    void reset_board();

private:
    Ui::MainWindow *ui; // create a pointer object of MainWindow class that is inside namespace Ui
};

#endif // MAINWINDOW_H
