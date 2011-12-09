#include "taskmybullet.h"
#include "texture.h"
#include "taskmanager.h"
#include "common.h"

taskMyBullet::taskMyBullet(const QPointF& pt, int zorder)
    : TaskChara(pt, zorder, true)
{
    m_size = QSize(32, 16);
    m_power     = 1;
    m_defence   = 1;
    m_damage    = 0;
}

void taskMyBullet::oneFrame()
{
    QPointF acc;

    m_pos += QPointF(0, -16);

    if(isOutOfScreen())
        doDelete();
}

void taskMyBullet::render(QPainter* painter)
{
    Texture::inst()->putSprite("MAIN", painter, m_pos.toPoint(), QPoint(0, 0), QSize(32, 32));
}

void taskMyBullet::addDamage(int power)
{
    m_damage += power;

    if(m_defence < m_damage)
    {
        doDelete();
    }
}

