#include "pista77.h"
#include <QtCore>
#include <QDebug>


Pista77::Pista77(QObject *parent, bool b) : QThread(parent)
{

}

Pista77::~Pista77()
{

}

int test6 = 0;
QMutex mutez;
void Pista77::run(){

   while(test6==0){

       if((this->getTrem()==2 && this->getPosicao()==1)|| (this->getTrem()==3 && this->getPosicao()==3)){
           qDebug() << "ENDTO 1";
           mutez.lock();
           if(this->getPosicao()==1){
                this->setLonget(this->getLonget()+320);
                this->setPosicao(2);
            }else{
               this->setLonget(this->getLonget()-320);
               this->setPosicao(1);
            }
           QThread::currentThread()->msleep(10000);
           mutez.unlock();

       }



      }

}

int Pista77::getPosicao() const
{
    return posicao;
}

void Pista77::setPosicao(int value)
{
    posicao = value;
}

int Pista77::getLate() const
{
    return late;
}

void Pista77::setLate(int value)
{
    late = value;
}


int Pista77::getLonget() const
{
    return longet;
}

void Pista77::setLonget(int value)
{
    longet = value;
}

int Pista77::getTrem() const
{
    return trem;
}

void Pista77::setTrem(int value)
{
    trem = value;
}
