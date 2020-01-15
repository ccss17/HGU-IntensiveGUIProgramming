#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
//#include <QProcess>
//#include <QTcpServer>
//#include "server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_Connect_clicked();

    void on_Disconnect_clicked();

    void connected();

    void disconnected();

    void onconnected_Server();

    void send();

    void read();

    void on_send_clicked();

    void on_Chat_returnPressed();

//    void error();

    void on_Chat_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
//    QList<QTcpSocket*> tcpsockets;
    QTcpSocket tcpsocket;
//    QTcpServer tcpserver;
    bool m_connected;
//    server _server;
    quint16 nextBlockSize;
//    QProcess *Process;
};
#endif // MAINWINDOW_H
