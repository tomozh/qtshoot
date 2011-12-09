#ifndef TASKCHARA_H
#define TASKCHARA_H

#include "task.h"

class TaskChara : public Task
{
public:
    TaskChara(const QPointF& pos = QPointF(0, 0), int zorder = 0, bool isBullet = false);

    const QPointF& getPos() const   { return m_pos; }
    const QSize& getSize() const    { return m_size; }
    int getDefence() const          { return m_defence; }
    int getDamage() const           { return m_damage; }
    int getPower() const            { return m_power; }
    bool isBullet() const           { return m_isBullet; }
    bool isOutOfScreen() const;

    virtual void addDamage(int power) = 0;

protected:
    QPointF m_pos;
    QSize   m_size;
    int     m_damage;
    int     m_defence;
    int     m_power;
    bool    m_isBullet;
};

#endif // TASKCHARA_H
