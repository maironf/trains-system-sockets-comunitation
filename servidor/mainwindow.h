#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QtConcurrent/QtConcurrent>
#include "myjob.h"
#include "myjob2.h"
#include "myjob3.h"
#include "myjob4.h"
#include "pista55.h"
#include "pista77.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Tcpserver;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     MyJob *mJob;
     MyJob2 *mJob2;
     MyJob3 *mJob3;
     MyJob4 *mJob4;
     Pista55 *pista55;
     Pista77 *pista77;

private slots:
    //void on_btnStart_clicked();

private:
    Ui::MainWindow *ui;

    QPropertyAnimation *animation;
    QPropertyAnimation *animation2;
    Tcpserver *mTcpserver;

public slots:
    void onValueChanged(int lati,int longi,int trem,int velo);
};

#endif // MAINWINDOW_H
