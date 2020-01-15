#include "server.h"
#include "ui_server.h"


// constructor
Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
}

Server::~Server()
{
    delete ui;
}


/***** create server *****/
void Server::onServerStart()
{
    server = new QTcpServer(this);

    // server related signal and slot connection must be made after its creation
    connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    // enable any ip address to join with port number 57375
    server->listen(QHostAddress::AnyIPv4, 57375);

    qInfo()<<server->serverAddress();
    qInfo()<<"isListening: "<<server->isListening();
    qInfo()<<QNetworkInterface::allAddresses();

    // code to find local IP address
    // https://stackoverflow.com/questions/13835989/get-local-ip-address-in-qt
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
        {
            qDebug() << "local ip address: "<< address.toString();
            ui->label_serverAddress->setText(address.toString());
        }
    }
    names.append("");
}


/***** close server and exit to main menu*****/
void Server::on_pushButton_serverExit_clicked()
{
    emit HomeClicked();
    server->close();
    qInfo()<<"isListening: "<<server->isListening();
    delete server;
    qInfo()<<"server pointer deleted";

    // clear chat board at exit
    ui->textEdit_serverChatView->clear();
    ui->textEdit_serverWrite->clear();

    // clear socket list
    sockets.clear();
}


/***** someone is attemting to connect *****/
void Server::onNewConnection()
{
    // append to sockets Qlist
    // NOTE!!! NEED TO CLEAR THIS LIST AT SERVER EXIT
    sockets.append(server->nextPendingConnection());
    connect(sockets.last(), SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    /* nextPendingConnection() returns the next pending connection as a connected QTcpSocket object.
     * this means that client's socket informaation is returned
     * therefore this must be save in a list if the server want connections to multiple clients
     * this does not mean that the server owns multiple sockets,
     * server and clients each have one socket open ????????????????????????? I don't know if this is right
     */
    qInfo()<<"someone has connected!";
}

/***** when someone has sent data *****/
void Server::onReadyRead()
{
    qInfo() << "someone sent a message!";
    // finding who sent the message
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    qDebug() << "cp1";

//    QString receivedMessage = sender->readLine(); // this code becomes problematic when "\n"is used alot
    QString receivedMessage = sender->readAll();
    qInfo() << receivedMessage;
    ui->textEdit_serverChatView->append(receivedMessage);
    qDebug() << "cp2";

    // send results to clients
    for(QTcpSocket *socket: sockets)
    {
        // qstring to char * conversion
        // https://stackoverflow.com/questions/2523765/qstring-to-char-conversion
        socket->write(receivedMessage.toLocal8Bit().data());
        qDebug() << "cp loop";
    }
    qDebug() << "cp3";
}

// send results to clients
void Server::on_pushButton_serverSend_clicked()
{
    qInfo()<<"send button clicked!";
    QString messageToSend = ui->label_name->text() + ":  " + ui->textEdit_serverWrite->toPlainText();
    ui->textEdit_serverChatView->append(messageToSend);
    for(QTcpSocket *socket: sockets)
    {
        socket->write(messageToSend.toLocal8Bit().data());
    }
    ui->textEdit_serverWrite->clear();
}


// set name label
void Server::onSetName(QString name)
{
    ui->label_name->setText(name);
    qDebug() << "signal received";
}
