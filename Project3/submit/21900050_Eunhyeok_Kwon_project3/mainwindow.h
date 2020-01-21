#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "server.h"
#include "client.h"

#include <QMainWindow>
#include <QTcpServer>

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

    void on_pushButton_exit_clicked();

    void on_pushButton_server_clicked();

    void on_pushButton_client_clicked();

    void moveHome();

    void on_lineEdit_name_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Server _Server;
    Client _Client;

signals:
    void ServerStart();
    void ClientStart();
    void SetName(QString name);
};
#endif // MAINWINDOW_H
