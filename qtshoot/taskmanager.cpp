#include "taskchara.h"
#include "taskmanager.h"


TaskManager::TaskManager()
    : m_myShipPos(0, 0)
{
}

TaskManager::~TaskManager()
{
    foreach(Task* task, m_task)
        delete  task;

    m_task.clear();
    m_enemyTask.clear();
}

void TaskManager::addTask(Task* task)
{
    m_task.append(task);
}

void TaskManager::addEnemyTask(TaskChara* task)
{
    m_enemyTask.insert(task);
    addTask(task);
}

void TaskManager::addMyTask(TaskChara* task)
{
    m_myTask.insert(task);
    addTask(task);
}

void TaskManager::oneFrame()
{
    foreach(Task* task, m_task)
    {
        task->oneFrame();
    }

    collisionCheck();

    Tasks::iterator it;
    for(it = m_task.begin(); it != m_task.end(); it++)
    {
        if((*it)->isDeleted())
        {
            if(typeid(*it).before(typeid(TaskChara*)))
            {
                TaskChara* task = dynamic_cast<TaskChara*>(*it);
                m_enemyTask.remove(task);
                m_myTask.remove(task);
            }

            delete (*it);
            it = m_task.erase(it);
            it--;
        }
    }
}

void TaskManager::render(QPainter* painter)
{
    foreach(Task* task, m_task)
    {
        task->render(painter);
    }
}

int TaskManager::getTaskCount() const
{
    return m_task.size();
}

void TaskManager::collisionCheck()
{
    foreach(TaskChara* myTask, m_myTask)
    {
        foreach(TaskChara* enemy, m_enemyTask)
        {
            if(!myTask->isBullet() || !enemy->isBullet())
            {
                QSize   size = (enemy->getSize() + myTask->getSize()) / 2;
                QPointF diff = enemy->getPos() - myTask->getPos();

                if(diff.x() < 0) diff.rx() = -diff.rx();
                if(diff.y() < 0) diff.ry() = -diff.ry();

                if((diff.x() <= size.width()) && (diff.y() <= size.height()))
                {
                    enemy->addDamage(myTask->getPower());
                    myTask->addDamage(enemy->getPower());
                }
            }
        }
    }
}

void TaskManager::setMyShipPos(const QPointF& pos)
{
    m_myShipPos = pos;
}

const QPointF& TaskManager::getMyShipPos() const
{
    return m_myShipPos;
}


