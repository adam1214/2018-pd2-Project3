#include "super_skill_times.h"
#include <QFont>

Super_skill_times::Super_skill_times(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    times = 5;

    // draw the text
    setPlainText(QString("Super skill times: ") + QString::number(times)); // Health: 10
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Super_skill_times::decrease()
{
    times--;
    setPlainText(QString("Super skill times: ") + QString::number(times));
}

int Super_skill_times::get_times()
{
    return times;
}
