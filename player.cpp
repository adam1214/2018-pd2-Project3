#include "player.h"
#include<QGraphicsScene>
#include<QObject>
#include <cstdlib>
#include"bullet.h"
#include"mainwindow.h"
#include<QPointF>
#include"polyitem.h"

Player::Player()
{

}

QRectF Player::boundingRect() const
{
    return QRect(0,0,50,50);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec=boundingRect();
    QBrush Brush(Qt::red);

    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}

qreal &Player::getX()
{
    QPointF location=this->pos();
    return location.rx();
}

qreal &Player::getY()
{
    QPointF location=this->pos();
    return location.ry();
}
