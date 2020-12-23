#ifndef THREADTRENS_H
#define THREADTRENS_H

#include <QThread>

class ThreadTrens : public QThread
{
    Q_OBJECT
public:
    explicit ThreadTrens(QObject *parent = 0);
    ~ThreadTrens();
protected:
    void run();
};

#endif // THREADTRENS_H
