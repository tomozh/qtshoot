#include "texture.h"
#include "common.h"
#include "taskmanager.h"
#include "taskexplode.h"
#include "taskenemybullet.h"
#include "taskenemy1.h"

taskEnemy1::taskEnemy1(const QPointF& pt, int zorder, const QPointF& vec)
    : TaskChara(pt, zorder, false)
    , m_frameCount(0)
    , m_vec(vec)
{
    m_size = QSize(20, 20);
    m_power     = 1;
    m_defence   = 1;
    m_damage    = 0;
}

void taskEnemy1::oneFrame()
{
    m_pos += m_vec;

    if(isOutOfScreen())
        doDelete();

    if((m_frameCount % 60) == 0)
    {
        const QPointF& myShip = TaskManager::inst()->getMyShipPos();

        QPointF delta = myShip - m_pos;
        double r = atan2(delta.y(), delta.x());
        double spd = 1.0;
        QPointF vec(cos(r) * spd, sin(r) * spd);

        TaskManager::inst()->addEnemyTask(new taskEnemyBullet(m_pos, 0, vec, QPointF(0, 0)));
    }

    m_frameCount++;
}

void taskEnemy1::render(QPainter* painter)
{
    Texture::inst()->putSprite(
                "MAIN",
                painter,
                m_pos.toPoint(),
                QPoint(32*4, 32),
                QSize(32, 32)
                );
}

void taskEnemy1::addDamage(int power)
{
    m_damage += power;

    if(m_defence < m_damage)
    {
        TaskManager::inst()->addTask(new taskExplode(m_pos, 0));
        doDelete();
    }
}

