#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    ui->stackedWidget_client->setCurrentIndex(0);   // always begin with join page
}

Client::~Client()
{
    delete ui;
}

/***** create client *****/
void Client::onClientStart()
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(onConnected())); // server related signal and slot connection must be made after its creation
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
    qInfo() << "client opened and socket created";
}


/***** disconnected from server *****/
void Client::onDisconnect()
{
    ui->textEdit_clientWrite->setReadOnly(true);
    ui->textEdit_clientWrite->setText("disconnected from server");
    ui->pushButton_clientSend->setDisabled(true);
    qInfo() << "disconnected signal";
}

// set name label
void Client::onSetName(QString name)
{
    ui->label_name->setText(name);
    ui->label_name_copy->setText(name);
}


/***** exit from server *****/
void Client::on_pushButton_clientExit_clicked()
{
    ui->stackedWidget_client->setCurrentIndex(0);
    QString messageToSend = ui->label_name->text() + "님이 나갔습니다.";
    socket->write(messageToSend.toLocal8Bit().data());

    socket->disconnectFromHost();
    qInfo() << "disconnected from server";
}

/***** close client *****/
void Client::on_pushButton_clientGoMain_clicked()
{
    emit HomeClicked();
    delete socket;
    qInfo() << "client closed and socket deleted";
}


/***** attempt to join a server *****/
void Client::on_pushButton_clientJoin_clicked()
{
    qInfo()<<socket->state();
    qInfo()<<"join to: "<<ui->lineEdit_clientJoinAddress->text();
    QString hostAddress = ui->lineEdit_clientJoinAddress->text();

    socket->connectToHost(hostAddress, 57375);
    qInfo()<<socket->state();

    // reset chat board at exit
    ui->textEdit_clientChatView->clear();
    ui->textEdit_clientWrite->setReadOnly(false);
    ui->textEdit_clientWrite->clear();
    ui->pushButton_clientSend->setEnabled(true);
}

/***** successfully connected to server *****/
void Client::onConnected()
{
    // change screen if connected
    ui->stackedWidget_client->setCurrentIndex(1);
    qInfo() << "successfully joined";
    QString messageToSend = ui->label_name->text() + "님이 들어왔습니다.";
    socket->write(messageToSend.toLocal8Bit().data());
}

/***** send data to server *****/
void Client::on_pushButton_clientSend_clicked()
{
    qInfo()<<"send button clicked!";
    QString messageToSend =  ui->label_name->text() + ":  " + ui->textEdit_clientWrite->toPlainText();
    socket->write(messageToSend.toLocal8Bit().data());
    ui->textEdit_clientWrite->clear();
}

/***** read data from server *****/
void Client::onReadyRead()
{
    qInfo() << "someone sent a message!";
//    QString receivedMessage = socket->readLine();
    QString receivedMessage = socket->readAll();
    qInfo() << receivedMessage;
    ui->textEdit_clientChatView->append(receivedMessage);
}


