#include "myjob.h"
#include <QtCore>
#include <QDebug>


MyJob::MyJob(QObject *parent, bool b) : QThread(parent)
{

}

MyJob::~MyJob()
{

}
int test1 = 0;

void MyJob::run(){

while(test1==0){

        if(this->getPosicao()==0){
            //if(this->getTrem()==4){
              //  this->setLate(this->getLate()+320);
            //}else{
                this->setLate(this->getLate()+90);
            //}
            this->setPosicao(1);
        }else if(this->getPosicao()==1){
            this->setLonget(this->getLonget()+70);
            this->setPosicao(2);
        }else if(this->getPosicao()==2){
            //if(this->getTrem()==4){
              //  this->setLate(this->getLate()-320);
            //}else{
                this->setLate(this->getLate()-90);
            //}
            this->setPosicao(3);
        }else if(this->getPosicao()==3){
            this->setLonget(this->getLonget()-70);
            this->setPosicao(0);
        }


    this->msleep(this->getVelocidade());

    emit direcao(this->getLate(),this->getLonget(),this->getTrem(),this->getVelocidade());

  }

}

int MyJob::getVelocidade() const
{
    return velocidade;
}

void MyJob::setVelocidade(int value)
{
    velocidade = value;
}

int MyJob::getPosicao() const
{
    return posicao;
}

void MyJob::setPosicao(int value)
{
    posicao = value;
}

int MyJob::getLate() const
{
    return late;
}

void MyJob::setLate(int value)
{
    late = value;
}


int MyJob::getLonget() const
{
    return longet;
}

void MyJob::setLonget(int value)
{
    longet = value;
}

int MyJob::getTrem() const
{
    return trem;
}

void MyJob::setTrem(int value)
{
    trem = value;
}
