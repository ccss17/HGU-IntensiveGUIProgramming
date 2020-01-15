#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget_main->insertWidget(1, &_Server);
    ui->stackedWidget_main->insertWidget(2, &_Client);

    ui->stackedWidget_main->setCurrentIndex(0); // always begin with main page

    connect(&_Server, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&_Client, SIGNAL(HomeClicked()), this, SLOT(moveHome()));

    connect(this, SIGNAL(ServerStart()), &_Server, SLOT(onServerStart()));
    connect(this, SIGNAL(ClientStart()), &_Client, SLOT(onClientStart()));

    connect(this, SIGNAL(SetName(QString)), &_Server, SLOT(onSetName(QString)));
    connect(this, SIGNAL(SetName(QString)), &_Client, SLOT(onSetName(QString)));

    // begin with buttons disabled so user need to type name
    ui->pushButton_server->setDisabled(true);
    ui->pushButton_client->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// must enter nickname to start
void MainWindow::on_lineEdit_name_textChanged(const QString &arg1)
{
    if(arg1.length()>0)
    {
        ui->pushButton_server->setEnabled(true);
        ui->pushButton_client->setEnabled(true);
    }
    else
    {
        ui->pushButton_server->setDisabled(true);
        ui->pushButton_client->setDisabled(true);
    }
}

/******************** Buttons ********************/

void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_server_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(1);
    emit ServerStart();
    emit SetName(ui->lineEdit_name->text());
}

void MainWindow::on_pushButton_client_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(2);
    emit ClientStart();
    emit SetName(ui->lineEdit_name->text());
}

void MainWindow::moveHome()
{
    ui->stackedWidget_main->setCurrentIndex(0);
}


