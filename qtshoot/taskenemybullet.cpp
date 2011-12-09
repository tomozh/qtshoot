#include "texture.h"
#include "common.h"
#include "taskmanager.h"
#include "taskenemybullet.h"

taskEnemyBullet::taskEnemyBullet(const QPointF& pt, int zorder, const QPointF& spd, const QPointF& acc)
    : TaskChara(pt, zorder, true)
    , m_spd(spd)
    , m_acc(acc)
    , m_frameCount(0)
    , m_anm(0)
{
    m_size = QSize(12, 12);
    m_power     = 1;
    m_defence   = 1;
    m_damage    = 0;
}

void taskEnemyBullet::oneFrame()
{
    m_pos += m_spd;
    m_spd += m_acc;

    if(isOutOfScreen())
        doDelete();

    if((m_frameCount % 8) == 0)
    {
        m_anm++;
        if(m_anm >= 4) m_anm = 0;
    }
}

void taskEnemyBullet::render(QPainter* painter)
{
    Texture::inst()->putSprite(
                "MAIN",
                painter,
                m_pos.toPoint(),
                QPoint(m_anm * 16, 64),
                QSize(16, 16)
                );
}

void taskEnemyBullet::addDamage(int power)
{
    m_damage += power;

    if(m_defence < m_damage)
        doDelete();
}
