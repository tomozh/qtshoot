#ifndef TASKMYBULLET_H
#define TASKMYBULLET_H

#include "taskchara.h"

class taskMyBullet : public TaskChara
{
public:
    taskMyBullet(const QPointF& pt, int zorder);

    virtual void oneFrame();
    virtual void render(QPainter* painter);
    virtual void addDamage(int power);
};

#endif // TASKMYBULLET_H
