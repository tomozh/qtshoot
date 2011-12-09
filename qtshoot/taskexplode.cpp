#include "taskexplode.h"
#include "texture.h"
#include "common.h"

taskExplode::taskExplode(const QPointF& pos, int zorder)
    : Task(zorder)
    , m_pos(pos)
    , m_timer(0)
    , m_anm(0)
{
}

void taskExplode::oneFrame()
{
    m_timer++;

    if(m_timer > 2)
    {
        m_timer = 0;
        m_anm++;

        if(m_anm >= 4)
            doDelete();
    }
}

void taskExplode::render(QPainter* painter)
{
    Texture::inst()->putSprite(
                "MAIN",
                painter,
                m_pos.toPoint(),
                QPoint((2 + m_anm) * 32, 64),
                QSize(32, 32)
                );
}
