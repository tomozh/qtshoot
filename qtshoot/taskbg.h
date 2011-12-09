#ifndef TASKBG_H
#define TASKBG_H

#include <QVector>
#include "common.h"
#include "task.h"

class Star
{
public:
    Star()
    {
        m_pos = QPointF(rand() % (SCR_X * 2) - (SCR_X / 2), rand() % SCR_Y);
        m_vec = QPointF(0, rand() % 4 + 1);
    }


    void step()
    {
        m_pos += m_vec;
        if(m_pos.y() > SCR_Y)
            m_pos = QPointF(rand() % (SCR_X * 2) - (SCR_X / 2), 0);
    }

    QPointF m_pos;
    QPointF m_vec;
};

typedef QVector<Star>   Stars;

class taskBG : public Task
{
public:
    taskBG(int zorder);

    virtual void oneFrame();
    virtual void render(QPainter* painter);

private:
    Stars   m_stars;
};

#endif // TASKBG_H
