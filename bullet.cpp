#include "bullet.h"
#include<QPointF>
#include <QList>
#include <QGraphicsScene>
#include <QTimer>
#include"myitem.h"
#include"player.h"
#include"mainwindow.h"
#include"win.h"
#include"gameover.h"

extern MainWindow * w;
Win *win;
Gameover *g;

bullet::bullet()
{

}

void bullet::fly_up()
{
    // if bullet collides with enemy, destroy both
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(MyItem)){
                // increase the score
                w->score->increase();
                w->Enemy_HP->decrease();
                if(w->Enemy_HP->getHealth()==0)
                {
                    win=new Win();
                    win->show();
                    delete w;
                }

                // remove them both
                //scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                // delete them both
                //delete colliding_items[i];
                delete this;
                return;
            }
        }

    setPos(x(), y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::fly_down()
{
    // if bullet collides with enemy, destroy both
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Player)){
                w->player_HP->decrease();
                if(w->player_HP->getHealth()==0)
                {
                    g=new Gameover();
                    g->show();
                    delete w;
                }
                // remove them both
                //scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                // delete them both
                //delete colliding_items[i];
                delete this;
                return;
            }
        }

    setPos(x(), y() + 3);
    if(y() > 871) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::fly_left_up()
{
    // if bullet collides with enemy, destroy both
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(MyItem)){
                // increase the score
                w->score->increase();
                w->Enemy_HP->decrease();
                if(w->Enemy_HP->getHealth()==0)
                {
                    win=new Win();
                    win->show();
                    delete w;
                }

                // remove them both
                //scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                // delete them both
                //delete colliding_items[i];
                delete this;
                return;
            }
        }

    setPos(x()-1.5, y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::fly_right_up()
{
    // if bullet collides with enemy, destroy both
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(MyItem)){
                // increase the score
                w->score->increase();
                w->Enemy_HP->decrease();
                if(w->Enemy_HP->getHealth()==0)
                {
                    win=new Win();
                    win->show();
                    delete w;
                }

                // remove them both
                //scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                // delete them both
                //delete colliding_items[i];
                delete this;
                return;
            }
        }

    setPos(x()+1.5, y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

qreal& bullet::getX()
{
    QPointF location=this->pos();
    return location.rx();
}

qreal& bullet::getY()
{
    QPointF location=this->pos();
    return location.ry();
}
