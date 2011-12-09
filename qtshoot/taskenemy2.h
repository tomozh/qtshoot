#ifndef TASKENEMY2_H
#define TASKENEMY2_H

#include <QPointF>
#include <QPainter>
#include "taskchara.h"

class taskEnemy2 : public TaskChara
{
public:
    taskEnemy2(const QPointF& pt, int zorder, const QPointF& vec, int seq);

    virtual void oneFrame();
    virtual void render(QPainter* painter);
    virtual void addDamage(int power);

private:
    int m_frameCount;
    QPointF m_vec;
    int m_seq;
};

#endif // TASKENEMY2_H
