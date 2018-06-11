#include "myitem.h"
#include<QGraphicsScene>
#include<QObject>
#include <cstdlib>
#include"bullet.h"
#include"mainwindow.h"
#include<QPointF>
#include"polyitem.h"

MyItem::MyItem()
{
    //random start rotation

    //set the speed
    speed=10;
    state=0;

    //random start position
    /*int StartX=0;
    int StartY=0;
    if((qrand()%1))
    {
        StartX=(qrand()%200);
        StartY=(qrand()%200);
    }
    else
    {
        StartX=(qrand()%-100);
        StartY=(qrand()%-100);
    }
    setPos(mapToParent(StartX,StartY));*/
}

QRectF MyItem::boundingRect() const
{
    return QRect(0,0,100,100);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec=boundingRect();
    QBrush Brush(Qt::black);

    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}

qreal& MyItem::getX()
{
    QPointF location=this->pos();
    return location.rx();
}

qreal& MyItem::getY()
{
    QPointF location=this->pos();
    return location.ry();
}

void  MyItem::advance(int phase)
{
    if(!phase) return;

    QPointF location=this->pos();

    if(state==0)
    {
        setPos(mapToParent(-(speed),0));
        if(location.rx()<=0)
        {
            state=1;
        }
    }
    if(state==1)
    {
        setPos(mapToParent((speed),0));
        if(location.rx()>=1100)
        {
            state=0;
        }
    }
}
