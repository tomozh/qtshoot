#ifndef TASKEXPLODE_H
#define TASKEXPLODE_H

#include "task.h"
#include <QPointF>

class taskExplode : public Task
{
public:
    taskExplode(const QPointF& pos = QPointF(0, 0), int zorder = 0);

    virtual void oneFrame();
    virtual void render(QPainter* painter);

private:
    QPointF m_pos;
    int m_timer;
    int m_anm;
};

#endif // TASKEXPLODE_H
