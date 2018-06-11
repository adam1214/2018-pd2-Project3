#include "health.h"

#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 20;

    // draw the text
    setPlainText(QString("Enemy HP: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Enemy HP: ") + QString::number(health)); // Health: 2
}

int Health::getHealth(){
    return health;
}
