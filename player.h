#ifndef PLAYER_H
#define PLAYER_H

#include"polyitem.h"
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QObject>
#include<QPointF>
#include"bullet.h"
#include"mainwindow.h"

class Player:public PolyItem
{
public:
    Player();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    qreal& getX();
    qreal& getY();
};

#endif // PLAYER_H
