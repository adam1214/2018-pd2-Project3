#ifndef PLAYER_HP_H
#define PLAYER_HP_H

#include <QGraphicsTextItem>

class Player_HP: public QGraphicsTextItem
{
public:
    Player_HP(QGraphicsItem * parent=0);
    void decrease();
    int getHealth();
private:
    int health;
};

#endif // PLAYER_HP_H
