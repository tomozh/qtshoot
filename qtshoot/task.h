#ifndef TASK_H
#define TASK_H

#include <QPointF>
#include <QSize>
#include <QList>

class QPainter;
class Task
{
    typedef QList<Task*> TaskList;

public:
    Task(int zorder = 0);

    virtual void oneFrame() = 0;
    virtual void render(QPainter* painter) = 0;

    bool isDeleted() const          { return m_delete; }
    int getZOrder() const           { return m_zorder; }

protected:
    void doDelete(){ m_delete = true; }
    bool isOutOfScreen() const;

protected:
    int     m_zorder;
    bool    m_delete;
};

#endif // TASK_H
