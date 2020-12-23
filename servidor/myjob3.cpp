#include "myjob3.h"
#include <QtCore>
#include <QDebug>


MyJob3::MyJob3(QObject *parent, bool b) : QThread(parent)
{

}

MyJob3::~MyJob3()
{

}

int test3 = 0;

void MyJob3::run(){

while(test3==0){

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

int MyJob3::getVelocidade() const
{
    return velocidade;
}

void MyJob3::setVelocidade(int value)
{
    velocidade = value;
}

int MyJob3::getPosicao() const
{
    return posicao;
}

void MyJob3::setPosicao(int value)
{
    posicao = value;
}

int MyJob3::getLate() const
{
    return late;
}

void MyJob3::setLate(int value)
{
    late = value;
}


int MyJob3::getLonget() const
{
    return longet;
}

void MyJob3::setLonget(int value)
{
    longet = value;
}

int MyJob3::getTrem() const
{
    return trem;
}

void MyJob3::setTrem(int value)
{
    trem = value;
}
