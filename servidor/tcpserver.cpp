#include "tcpserver.h"
#include <QTcpSocket>
#include <QTcpServer>
#include <QTextStream>
#include <qtcpserver.h>
#include <qtcpsocket.h>
#include <QString>
#include <QTextCodec>
#include <QStringList>

Tcpserver::Tcpserver(QObject *parent) : QTcpServer(parent)
{

    server = new QTcpSocket(this);
    connect(this,&Tcpserver::newConnection,[&](){
        QByteArray data = server->readLine(); //Leio o dado enviado pelo client
        QString DataAsString = QTextCodec::codecForMib(106)->toUnicode(data); //converto em string
        qDebug() << DataAsString;
        QStringList pieces = DataAsString.split( "/" ); //corta a string recebida
        QString vel = pieces.value( pieces.length() -1); //velocidade
        QString trem = pieces.value( pieces.length() -2); //trem
        qDebug() << vel;
        server = nextPendingConnection();
        if(data!=""){
            this->setVelocidade(vel.toInt());
            this->setTrem(trem.toInt());
        }

        qDebug() << this->getVelocidade();
        server->write("hello client\r\n");
        server->flush();

    });


}

int Tcpserver::getTrem() const
{
    return trem;
}

void Tcpserver::setTrem(int value)
{
    trem = value;
}

int Tcpserver::getVelocidade() const
{
    return velocidade;
}

void Tcpserver::setVelocidade(int value)
{
    velocidade = value;
}


void Tcpserver::readyRead()
{

    QByteArray data = server->readAll();
    qDebug() << data;

}

void Tcpserver::envia()
{


}
