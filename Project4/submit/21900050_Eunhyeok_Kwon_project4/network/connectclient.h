#ifndef CONNECTCLIENT_H
#define CONNECTCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QPoint>
#include <string>
#include <cstdlib>

class ConnectClient : public QObject
{
    Q_OBJECT
public:
    ConnectClient();
    ~ConnectClient();

    void sendData();                // sends data to client
    void makeConnectionTo(QString ipAddress);
    void closeConnection();

    void sendDataType(QString type);                // sends data to client
    void sendStoneMoveData(QPoint pos);

    QTcpSocket *getSocket() const;

signals:
    void opponentMadeMove(QPoint pos);

public slots:
    void onReadyRead();

private:
    QTcpSocket *socket;
};

#endif // CONNECTCLIENT_H
