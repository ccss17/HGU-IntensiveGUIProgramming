#include "connectclient.h"

ConnectClient::ConnectClient()
{
    socket = new QTcpSocket();

//    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

ConnectClient::~ConnectClient()
{
    delete socket;
}

void ConnectClient::sendData()
{
    qInfo() << "data sent";
    socket->write("client dataSend testing...");
}


void ConnectClient::sendDataType(QString type)
{
    socket->write((type+"\n").toLocal8Bit().data());
}

void ConnectClient::sendStoneMoveData(QPoint pos)
{
    socket->write((QString::number(pos.x())+"\n").toLocal8Bit().data());
    socket->write((QString::number(pos.y())+"\n").toLocal8Bit().data());
}


void ConnectClient::makeConnectionTo(QString ipAddress)
{
    socket->connectToHost(ipAddress, 13243);      /// ip for testing
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void ConnectClient::closeConnection()
{
    socket->close();
}

void ConnectClient::onReadyRead()
{
    qInfo() << "onReadyRead slot called(client)";
    QString receivedDataType = socket->readLine();                      // read data type
    if("stone_move\n" == receivedDataType)
    {
        int x = std::atoi(socket->readLine());
        int y = std::atoi(socket->readLine());
        emit opponentMadeMove(QPoint(x,y));
    }
    else
    {
        qInfo() << socket->readAll();
    }
}

QTcpSocket *ConnectClient::getSocket() const
{
    return socket;
}
