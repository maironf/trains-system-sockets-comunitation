#ifndef PISTA55_H
#define PISTA55_H

#include <QObject>
#include <QDebug>
#include <QThread>


class Pista55 :public QThread
{
    Q_OBJECT
public:
    explicit Pista55(QObject *parent = 0, bool b = false);
    ~Pista55();
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


public slots:


};


#endif // MYJOB_H
