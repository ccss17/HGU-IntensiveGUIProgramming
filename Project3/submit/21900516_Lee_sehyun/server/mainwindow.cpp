#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QtNetwork>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _server(this)
{
    ui->setupUi(this);
    this->setWindowTitle("Project3 남들과 함께 얘기해요 서버편");
    connect(&_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Open_clicked()
{
    _server.listen(QHostAddress::Any, 8010);
    QList<QHostAddress> addrlist = QNetworkInterface::allAddresses();
    foreach(QHostAddress addr, addrlist){
        if ( 0 >= addr.toIPv4Address() ) continue;
        else {
              if (addr.toString().contains("127.0.0.1") ) continue;
              else { ui->ip->append(addr.toString());  break; }
        }
    }
}

void MainWindow::onNewConnection()
{
   QTcpSocket *clientSocket = _server.nextPendingConnection();
   connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
   connect(clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));

    _sockets.push_back(clientSocket);
}

void MainWindow::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
        _sockets.removeOne(sender);
    }
}

void MainWindow::onReadyRead()
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
//    QByteArray datas = sender->readAll();
    QString strRead = sender->readLine();



    for (QTcpSocket* socket : _sockets) {
        QTextStream out(socket);
        if (socket != sender)
            out<<strRead;
//            socket->write(QByteArray::fromStdString(datas.toStdString()));
    }
}
