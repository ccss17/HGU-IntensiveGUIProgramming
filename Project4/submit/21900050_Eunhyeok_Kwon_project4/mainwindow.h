#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mechanism/connectgame.h"
#include "graphics/connectboard.h"
#include "network/connectserver.h"
#include "network/connectclient.h"
#include "ai/ai1.h"

#include <QMainWindow>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**** game flow functions for game choice ****/
    void gameflow_mousePress_singleplay(QPoint pos);
    void gameflow_mouseMove_singleplay(QPoint pos);

    void gameflow_mousePress_multiplay(QPoint pos);
    void gameflow_mouseMove_multiplay(QPoint pos);

    void gameflow_mousePress_host(QPoint pos);
    void gameflow_mouseMove_host(QPoint pos);

    void gameflow_mousePress_join(QPoint pos);
    void gameflow_mouseMove_join(QPoint pos);



private slots:
    /**** page_name ****/
    void on_lineEdit_userName_textChanged(const QString &arg1);
    void on_lineEdit_userName_returnPressed();
    void on_pushButton_submitName_clicked();

    /**** page_menu ****/
    void on_pushButton_single_clicked();
    void on_pushButton_multi_clicked();
    void on_pushButton_host_clicked();
    void on_pushButton_join_clicked();

    void on_stackedWidget_currentChanged(int currentPageIdx);

    /**** events ****/
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    void on_pushButton_exit_clicked();

    void on_pushButton_joinServer_clicked();

    void onClientConnectedToServer();

    void onOpponentMadeMove(QPoint pos);

//    void connected();

signals:
    void readReady();

private:
    Ui::MainWindow *ui;
    ConnectGame *connectGame;
    ConnectBoard *connectBoard;
    ConnectServer *connectServer;
    ConnectClient *connectClient;
    AI1 *ai1;

    QImage *cleanTransparentLayer;

    QString userName;               // stores username
    enum page {
        page_name = 0,
        page_menu = 1,
        page_join = 2,
        page_game = 3
    };                              // for stack-view page change
    enum gameType {
        gameType_none = 0,
        gameType_single = 1,
        gameType_multi = 2,
        gameType_host = 3,
        gameType_join = 4
    };                              // for page_game initialization
    gameType gameChoise;
    bool playing;                   // for mouse event control


    State_type server_color;
    State_type client_color;


    int test =1;
};
#endif // MAINWINDOW_H
