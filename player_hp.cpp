#include "player_hp.h"
#include <QFont>

Player_HP::Player_HP(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    health = 10;

    // draw the text
    setPlainText(QString("Player HP: ") + QString::number(health)); // Health: 10
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}
void Player_HP::decrease(){
    health--;
    setPlainText(QString("Player HP: ") + QString::number(health)); // Health: 2
}

int Player_HP::getHealth(){
    return health;
}
