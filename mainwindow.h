#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "polyitem.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include<QObject>
#include "bullet.h"
#include"myitem.h"
#include <QKeyEvent>
#include<QDialog>
#include<QtCore>
#include <QGraphicsView>
#include <QWidget>
#include<QtGui>
#include"player.h"
#include"score.h"
#include"health.h"
#include"player_hp.h"
#include"super_skill_times.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int enemy_x=1000;
    int enemy_y=5;
    QGraphicsScene *scene;
    Score * score;
    Health * Enemy_HP;
    Player_HP * player_HP;
    Super_skill_times * s;

public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    //virtual void mousePressEvent(QMouseEvent *e);
    void enemy_shot();
    //void enemy_HP();

private:
    Ui::MainWindow *ui;
    //QGraphicsPixmapItem *player;

    //QGraphicsPixmapItem *enemy;
    QTimer *timer;
    QTimer *timer1;
    QTimer *timer3;
    QTimer *timer4;
};

#endif // MAINWINDOW_H














