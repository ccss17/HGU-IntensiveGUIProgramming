#include "connectserver.h"

ConnectServer::ConnectServer()
{
    server = new QTcpServer();
    socket = new QTcpSocket();
    connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

ConnectServer::~ConnectServer()
{
    /// the order is important; delete socket first, then server
    delete socket;
    delete server;
}

void ConnectServer::openServer()
{
    /// server begins listening on creation???
    server->listen(QHostAddress::Any, 13243);
//    /// find local IP address            https://stackoverflow.com/questions/13835989/get-local-ip-address-in-qt
//    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
//    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
//        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
//        {
//            qDebug() << "local ip address: "<< address.toString();
//        }
//    }
//    qDebug() << server->serverAddress();
//    qInfo() << socket->state();                 /// it's unconnected state when there is no connection made yet
}

void ConnectServer::closeServer()
{
    socket->disconnectFromHost();
    socket->close();
    server->close();
    qInfo() << "server closed";
}

void ConnectServer::sendDataType(QString type)
{
    socket->write((type+"\n").toLocal8Bit().data());
}

void ConnectServer::sendStoneMoveData(QPoint pos)
{
    socket->write((QString::number(pos.x())+"\n").toLocal8Bit().data());
    socket->write((QString::number(pos.y())+"\n").toLocal8Bit().data());
}

void ConnectServer::checkBytesAvailable()
{
    qInfo() << socket->bytesAvailable();
}

/*** for connecting  to a new client ***/
void ConnectServer::onNewConnection()
{
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    qInfo() << "someone joined server";
    qInfo() << socket->state();
    server->close();
}

void ConnectServer::onReadyRead()
{
    qInfo() << "onReadyRead slot called(server)";
    qInfo() << socket->readLine();
    int x = std::atoi(socket->readLine());
    int y = std::atoi(socket->readLine());
    emit opponentMadeMove(QPoint(x,y));

}
