#ifndef PISTA77_H
#define PISTA77_H

#include <QObject>
#include <QDebug>
#include <QThread>


class Pista14 :public QThread
{
    Q_OBJECT
public:
    explicit Pista14(QObject *parent = 0, bool b = false);
    ~Pista14();
    void run();
    int trem;
    int posicao;
    int late;
    int longet;
    //QString name;

    int getTrem() const;
    void setTrem(int value);

    int getPosicao() const;
    void setPosicao(int value);

    int getLate() const;
    void setLate(int value);

    int getLonget() const;
    void setLonget(int value);

signals:
    void direcao(int,int,int);

public slots:


};


#endif // MYJOB_H
