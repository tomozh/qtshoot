#include <QPointF>
#include <QRectF>
#include "task.h"
#include "common.h"

Task::Task(int zorder)
    : m_zorder(zorder)
    , m_delete(false)
{
}
