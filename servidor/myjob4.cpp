#include "myjob4.h"
#include <QtCore>
#include <QDebug>


MyJob4::MyJob4(QObject *parent, bool b) : QThread(parent)
{

}

MyJob4::~MyJob4()
{

}

int test4 = 0;

void MyJob4::run(){

while(test4==0){

          if(this->getPosicao()==0){
              //if(this->getTrem()==4){
                  this->setLate(this->getLate()+320);
              //}else{
                  //this->setLate(this->getLate()+90);
              //}
              this->setPosicao(1);
          }else if(this->getPosicao()==1){
              this->setLonget(this->getLonget()+70);
              this->setPosicao(2);
          }else if(this->getPosicao()==2){
              //if(this->getTrem()==4){
                 this->setLate(this->getLate()-320);
              //}else{
                  //this->setLate(this->getLate()-90);
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

int MyJob4::getVelocidade() const
{
    return velocidade;
}

void MyJob4::setVelocidade(int value)
{
    velocidade = value;
}

int MyJob4::getPosicao() const
{
    return posicao;
}

void MyJob4::setPosicao(int value)
{
    posicao = value;
}

int MyJob4::getLate() const
{
    return late;
}

void MyJob4::setLate(int value)
{
    late = value;
}


int MyJob4::getLonget() const
{
    return longet;
}

void MyJob4::setLonget(int value)
{
    longet = value;
}

int MyJob4::getTrem() const
{
    return trem;
}

void MyJob4::setTrem(int value)
{
    trem = value;
}
