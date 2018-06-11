#ifndef MYITEM_H
#define MYITEM_H

#include"polyitem.h"
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QObject>
#include<QPointF>
#include"mainwindow.h"
#include"bullet.h"


class MyItem:public PolyItem
{
public:
    MyItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    qreal& getX();
    qreal& getY();
    int state;
public slots:
    void advance(int phase);
private:
    qreal speed;

};

#endif // MYITEM_H
