#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QtDebug>
#include <QString>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void on_pushButton_clientGoMain_clicked();
    void onClientStart();
    void onConnected();

    void on_pushButton_clientJoin_clicked();
    void on_pushButton_clientExit_clicked();

    void on_pushButton_clientSend_clicked();
    void onReadyRead();
    void onDisconnect();
    void onSetName(QString name);

private:
    Ui::Client *ui;
    QTcpSocket *socket;

signals:
    void HomeClicked();
};

#endif // CLIENT_H
