#ifndef MYJOB_H
#define MYJOB_H

#include <QObject>
#include <QDebug>
#include <QThread>


class MyJob :public QThread
{
    Q_OBJECT
public:
    explicit MyJob(QObject *parent = 0, bool b = false);
    ~MyJob();
    void run();
    int trem;
    int posicao;
    int late;
    int longet;
    int velocidade;
    //QString name;

    int getTrem() const;
    void setTrem(int value);

    int getPosicao() const;
    void setPosicao(int value);

    int getLate() const;
    void setLate(int value);

    int getLonget() const;
    void setLonget(int value);

    int getVelocidade() const;
    void setVelocidade(int value);

signals:
    void direcao(int,int,int,int);

public slots:


};


#endif // MYJOB_H
