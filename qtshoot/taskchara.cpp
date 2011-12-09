#include "taskchara.h"
#include "common.h"
#include <QtGui>

TaskChara::TaskChara(const QPointF& pos, int zorder, bool isBullet)
    : Task(zorder)
    , m_pos(pos)
    , m_isBullet(isBullet)
    , m_power(0)
    , m_defence(0)
    , m_damage(0)
{
}

bool TaskChara::isOutOfScreen() const
{
    const QRectF area(-64, -64, SCR_X + 64, SCR_Y + 64);
    return !area.contains(m_pos);
}
