#ifndef MYJOB3_H
#define MYJOB3_H

#include <QObject>
#include <QDebug>
#include <QThread>


class MyJob3 :public QThread
{
    Q_OBJECT
public:
    explicit MyJob3(QObject *parent = 0, bool b = false);
    ~MyJob3();
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


#endif // MYJOB3_H
