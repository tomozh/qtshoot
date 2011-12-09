#ifndef MYSHIPTASK_H
#define MYSHIPTASK_H

#include <QtGui>
#include "taskchara.h"

class taskMyShip : public TaskChara
{
    enum State
    {
        START,
        IDLE,
        CLASH,
    };

public:
    taskMyShip(const QPointF& pt, int zorder);

    virtual void oneFrame();
    virtual void render(QPainter* painter);
    virtual void addDamage(int power);

private:
    State m_state;
    int m_frameCount;
    int m_timer;
};

#endif // MYSHIPTASK_H
