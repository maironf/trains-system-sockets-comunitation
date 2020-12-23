#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <qtcpserver.h>
#include <qtcpsocket.h>

class QTcpSocket;

class Tcpserver : public QTcpServer
{
    Q_OBJECT
public:
    explicit Tcpserver(QObject *parent=0);
    int velocidade;
    int trem;

    int getVelocidade() const;
    void setVelocidade(int value);

    int getTrem() const;
    void setTrem(int value);

signals:

public slots:
    void envia();
    void readyRead();
 private:
    QTcpSocket *server;



};

#endif // TCPSERVER_H
