#ifndef POLYITEM_H
#define POLYITEM_H
#include<QPointF>
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QObject>


class PolyItem:public QGraphicsItem
{
public:
    PolyItem();

    virtual QRectF boundingRect() const=0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)=0;
    virtual qreal& getX()=0;
    virtual qreal& getY()=0;
};

#endif // POLYITEM_H
