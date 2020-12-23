#include "pista55.h"
#include <QtCore>
#include <QDebug>


Pista55::Pista55(QObject *parent, bool b) : QThread(parent)
{

}

Pista55::~Pista55()
{

}

int test5 = 0;
QMutex mutex;
void Pista55::run(){

while(test5==0){

  if((this->getTrem()==1 && this->getPosicao()==1)|| (this->getTrem()==2 && this->getPosicao()==3)){
      qDebug() << "ENTRO";
      mutex.lock();
      if(this->getPosicao()==1){
           this->setLonget(this->getLonget()+70);
           this->setPosicao(2);
       }else{
          this->setLonget(this->getLonget()-70);
          this->setPosicao(2);
       }

      QThread::currentThread()->msleep(10000);
      mutex.unlock();

    }
  }

}

int Pista55::getPosicao() const
{
    return posicao;
}

void Pista55::setPosicao(int value)
{
    posicao = value;
}

int Pista55::getLate() const
{
    return late;
}

void Pista55::setLate(int value)
{
    late = value;
}


int Pista55::getLonget() const
{
    return longet;
}

void Pista55::setLonget(int value)
{
    longet = value;
}

int Pista55::getTrem() const
{
    return trem;
}

void Pista55::setTrem(int value)
{
    trem = value;
}
