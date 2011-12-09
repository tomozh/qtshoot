#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "task.h"
#include <QList>
#include <QSet>

class TaskChara;
class QPainter;
class TaskManager
{
    typedef QList<Task*> Tasks;
    typedef QSet<TaskChara*> CharaTasks;

private:
    TaskManager();

public:
    static TaskManager* inst()
    {
        static TaskManager obj;
        return &obj;
    }

    virtual ~TaskManager();
    void oneFrame();
    void render(QPainter* painter);

    void addTask(Task* task);
    void addEnemyTask(TaskChara* task);
    void addMyTask(TaskChara* task);

    int getTaskCount() const;
    void collisionCheck();

    void setMyShipPos(const QPointF& pos);
    const QPointF& getMyShipPos() const;

private:
    Tasks    m_task;
    CharaTasks m_enemyTask;
    CharaTasks m_myTask;
    QPointF m_myShipPos;
};

#endif // TASKMANAGER_H
