#include "myjob2.h"
#include <QtCore>
#include <QDebug>


MyJob2::MyJob2(QObject *parent, bool b) : QThread(parent)
{

}

MyJob2::~MyJob2()
{

}

int test2 = 0;

void MyJob2::run(){

while(test2==0){

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

int MyJob2::getVelocidade() const
{
    return velocidade;
}

void MyJob2::setVelocidade(int value)
{
    velocidade = value;
}

int MyJob2::getPosicao() const
{
    return posicao;
}

void MyJob2::setPosicao(int value)
{
    posicao = value;
}

int MyJob2::getLate() const
{
    return late;
}

void MyJob2::setLate(int value)
{
    late = value;
}


int MyJob2::getLonget() const
{
    return longet;
}

void MyJob2::setLonget(int value)
{
    longet = value;
}

int MyJob2::getTrem() const
{
    return trem;
}

void MyJob2::setTrem(int value)
{
    trem = value;
}
