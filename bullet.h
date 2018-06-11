#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include"mainwindow.h"

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    qreal& getX();
    qreal& getY();

public slots:
    void fly_up();
    void fly_down();
    void fly_left_up();
    void fly_right_up();
};

#endif // BULLET_H
