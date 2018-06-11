#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T19:17:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bullet.cpp \
    myitem.cpp \
    player.cpp \
    score.cpp \
    health.cpp \
    player_hp.cpp \
    win.cpp \
    gameover.cpp \
    polyitem.cpp \
    super_skill_times.cpp

HEADERS  += mainwindow.h \
    bullet.h \
    myitem.h \
    player.h \
    score.h \
    health.h \
    player_hp.h \
    win.h \
    gameover.h \
    polyitem.h \
    super_skill_times.h

FORMS    += mainwindow.ui \
    win.ui \
    gameover.ui

RESOURCES += \
    res.qrc
