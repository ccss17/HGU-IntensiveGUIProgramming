#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QtDebug>
#include <QNetworkInterface>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

private:
    Ui::Server *ui;
    QTcpServer *server;
    QList<QTcpSocket*> sockets;    // used list becuase many people are going to join the server
    QList<QString> names;

signals:
    void HomeClicked();

private slots:
    void on_pushButton_serverExit_clicked();
    void onServerStart();
    void onNewConnection();
    void onReadyRead();
    void on_pushButton_serverSend_clicked();
    void onSetName(QString name);
};

#endif // SERVER_H
