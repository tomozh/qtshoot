#include "taskbg.h"
#include "texture.h"
#include "taskmanager.h"
#include <QtGui>

taskBG::taskBG(int zorder)
    : Task(zorder)
{
    m_stars.resize(100);
}

void taskBG::oneFrame()
{
    int i;
    for(i = 0; i < m_stars.size(); i++)
        m_stars[i].step();
}

void taskBG::render(QPainter* painter)
{
    painter->setBrush(QBrush(Qt::black));
    painter->drawRect(0, 0, SCR_X, SCR_Y);

    int i;
    for(i = 0; i < m_stars.size(); i++)
    {
        const Star& star = m_stars[i];
        QPoint  pt = star.m_pos.toPoint();
        const QPointF& myShip = TaskManager::inst()->getMyShipPos();

        pt.rx() += ((SCR_X - myShip.x()) * star.m_vec.y()) / 10;

        Texture::inst()->putSprite(
                    "MAIN",
                    painter,
                    pt,
                    QPoint(0, 32),
                    QSize(16, 16)
                    );
    }
}
