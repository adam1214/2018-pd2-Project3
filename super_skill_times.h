#ifndef SUPER_SKILL_TIMES_H
#define SUPER_SKILL_TIMES_H
#include <QGraphicsTextItem>

class Super_skill_times:public QGraphicsTextItem
{
public:
    Super_skill_times(QGraphicsItem * parent=0);
    void decrease();
    int get_times();
private:
    int times;
};

#endif // SUPER_SKILL_TIMES_H
