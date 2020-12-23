#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QDebug>
#include "myjob.h"
#include "myjob2.h"
#include "myjob4.h"
#include "myjob3.h"
#include "tcpserver.h"
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create an instance of MyThread (TRENS)
    mJob = new MyJob(this);
    mJob2 = new MyJob2(this);
    mJob3 = new MyJob3(this);
    mJob4 = new MyJob4(this);
    //pistas compartilhadas
    pista55 = new Pista55(this);
    pista77 = new Pista77(this);

    //TCP server
    mTcpserver = new Tcpserver(this);
    mTcpserver->setVelocidade(-15); //velocidade para desconsiderar
    mTcpserver->setTrem(-1); //trem para desconsiderar

    if(!mTcpserver->listen(QHostAddress::Any,80)){
        qDebug() << "server não startou";
    }else{
       qDebug() << "server startou";
    }

    //inicializadores
    mJob->setPosicao(0);
    mJob->setTrem(1);
    mJob->setLate(60);
    mJob->setLonget(40);
    mJob->setVelocidade(500);
    mJob->start();

    //pista77->start();
    //pista55->start();

    mJob2->setPosicao(0);
    mJob2->setTrem(2);
    mJob2->setLate(180);
    mJob2->setLonget(40);
    mJob2->setVelocidade(1000);
    mJob2->start();

    mJob3->setPosicao(0);
    mJob3->setTrem(3);
    mJob3->setLate(290);
    mJob3->setLonget(40);
    mJob3->setVelocidade(1000);
    mJob3->start();

    mJob4->setPosicao(0);
    mJob4->setTrem(4);
    mJob4->setLate(60);
    mJob4->setLonget(130);
    mJob4->setVelocidade(1000);
    mJob4->start();

    connect(mJob,&MyJob::direcao,this,&MainWindow::onValueChanged);
    connect(mJob2,&MyJob2::direcao,this,&MainWindow::onValueChanged);
    connect(mJob3,&MyJob3::direcao,this,&MainWindow::onValueChanged);
    connect(mJob4,&MyJob4::direcao,this,&MainWindow::onValueChanged);
    qDebug() << "rodando";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onValueChanged(int lat, int langi,int trem,int velo)
{

    int vel = velo;
    if(trem==1){
        animation = new QPropertyAnimation(ui->pushButton,"geometry");
        animation->setDuration(vel);
        animation->setStartValue(ui->pushButton->geometry());
        animation->setEndValue(QRect(lat,langi,31,23));
        animation->start();
    }else if(trem==2){
        animation2 = new QPropertyAnimation(ui->pushButton_2,"geometry");
        animation2->setDuration(vel);
        animation2->setStartValue(ui->pushButton_2->geometry());
        animation2->setEndValue(QRect(lat,langi,31,23));
        animation2->start();
    }else if(trem==3){
        animation2 = new QPropertyAnimation(ui->pushButton_3,"geometry");
        animation2->setDuration(vel);
        animation2->setStartValue(ui->pushButton_3->geometry());
        animation2->setEndValue(QRect(lat,langi,31,23));
        animation2->start();
    }else if(trem==4){
        animation2 = new QPropertyAnimation(ui->pushButton_4,"geometry");
        animation2->setDuration(vel);
        animation2->setStartValue(ui->pushButton_4->geometry());
        animation2->setEndValue(QRect(lat,langi,31,23));
        animation2->start();
    }

    if(mTcpserver->getVelocidade()!=(-15)){

        //verifica para qual trem sera alterada a velocidade e altera a velocidade
        if(mTcpserver->getTrem()==1){
            mJob->setVelocidade(mTcpserver->getVelocidade());
        }else if(mTcpserver->getTrem()==2){
            mJob2->setVelocidade(mTcpserver->getVelocidade());
        }else if(mTcpserver->getTrem()==3){
            mJob3->setVelocidade(mTcpserver->getVelocidade());
        }else if(mTcpserver->getTrem()==4){
            mJob4->setVelocidade(mTcpserver->getVelocidade());
        }
    }

}


