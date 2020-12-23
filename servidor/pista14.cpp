#include "pista14.h"
#include <QtCore>
#include <QDebug>


Pista14::Pista14(QObject *parent, bool b) : QThread(parent)
{

}

Pista14::~Pista14()
{

}

int pista4 = 0;
QMutex mutey;
void Pista14::run(){

   while(pista4==0){

       if((this->getTrem()==2 && this->getPosicao()==1)|| (this->getTrem()==3 && this->getPosicao()==3)){
           qDebug() << "ENDTO 1";
           mutey.lock();
           if(this->getPosicao()==1){
                this->setLonget(this->getLonget()+70);
                this->setPosicao(2);
            }else{
               this->setLonget(this->getLonget()-70);
               this->setPosicao(2);
            }
           QThread::currentThread()->msleep(10000);
           mutey.unlock();
       }



      }

}

int Pista14::getPosicao() const
{
    return posicao;
}

void Pista14::setPosicao(int value)
{
    posicao = value;
}

int Pista14::getLate() const
{
    return late;
}

void Pista14::setLate(int value)
{
    late = value;
}


int Pista14::getLonget() const
{
    return longet;
}

void Pista14::setLonget(int value)
{
    longet = value;
}

int Pista14::getTrem() const
{
    return trem;
}

void Pista14::setTrem(int value)
{
    trem = value;
}
