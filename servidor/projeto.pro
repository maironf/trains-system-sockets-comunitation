QT       += core gui concurrent
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    myjob.cpp \
    myjob2.cpp \
    myjob3.cpp \
    myjob4.cpp \
    pista14.cpp \
    pista55.cpp \
    pista77.cpp \
    tcpserver.cpp

HEADERS += \
    mainwindow.h \
    myjob.h \
    myjob2.h \
    myjob3.h \
    myjob4.h \
    pista14.h \
    pista55.h \
    pista77.h \
    tcpserver.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
