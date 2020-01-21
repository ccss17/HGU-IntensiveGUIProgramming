#ifndef CONNECTSERVER_H
#define CONNECTSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QPoint>
#include <string>

class ConnectServer: public QObject        /// must inherit QObject to use signal and slot
{
    Q_OBJECT
public:
    ConnectServer();
    ~ConnectServer();

    void openServer();
    void closeServer();             // disables new connections

    void sendDataType(QString type);                // sends data to client
    void sendStoneMoveData(QPoint pos);
    void checkBytesAvailable();

public slots:
    /// clost must have its implementation in the cpp file to be compiled
    void onNewConnection();         /// newConnection() signal is then emitted each time a client connects to the server.
    void onReadyRead();             // receive data from client

signals:
    void opponentMadeMove(QPoint pos);

private:
    QTcpServer *server;
    QTcpSocket *socket;             /// only one connection is required to play the game; maybe could add spectator mode later
};

#endif // CONNECTSERVER_H
