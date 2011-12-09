#ifndef TASKENEMYBULLET_H
#define TASKENEMYBULLET_H

#include "taskchara.h"

class taskEnemyBullet : public TaskChara
{
public:    
    taskEnemyBullet(const QPointF& pt, int zorder, const QPointF& spd, const QPointF& acc);

    virtual void oneFrame();
    virtual void render(QPainter* painter);
    virtual void addDamage(int power);

protected:
    QPointF m_spd;
    QPointF m_acc;
    int m_anm;
    int m_frameCount;
};

#endif // TASKENEMYBULLET_H
