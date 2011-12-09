#ifndef TASKENEMY1_H
#define TASKENEMY1_H

#include <QPointF>
#include <QPainter>
#include "taskchara.h"

class taskEnemy1 : public TaskChara
{
public:
    taskEnemy1(const QPointF& pt, int zorder, const QPointF& vec);

    virtual void oneFrame();
    virtual void render(QPainter* painter);
    virtual void addDamage(int power);

private:
    int m_frameCount;
    QPointF m_vec;
};

#endif // TASKENEMY1_H
