#include "texture.h"
#include "common.h"
#include "taskmanager.h"
#include "taskexplode.h"
#include "taskenemybullet.h"
#include "taskenemy2.h"

taskEnemy2::taskEnemy2(const QPointF& pt, int zorder, const QPointF& vec, int seq)
    : TaskChara(pt, zorder, false)
    , m_frameCount(0)
    , m_vec(vec)
    , m_seq(seq)
{
    if(m_seq == 0)
    {
        m_size = QSize(32*3-16, 64-16);
        m_power     = 1;
        m_defence   = 100;
        m_damage    = 0;
    }
    else
    {
        m_size = QSize(32*2-16, 64-16);
        m_power     = 1;
        m_defence   = 40;
        m_damage    = 0;
    }
}

void taskEnemy2::oneFrame()
{
    m_pos += m_vec;

    if(isOutOfScreen())
        doDelete();

    m_frameCount++;
}

void taskEnemy2::render(QPainter* painter)
{
    QPoint pt;
    QSize size;

    if(m_seq == 0)
    {
        size = QSize(32*3, 64);
        pt = QPoint(32*1, 32*3);
    }
    else
    {
        size = QSize(32*2, 64);
        pt = QPoint(32*4, 32*3);
    }

    Texture::inst()->putSprite(
                "MAIN",
                painter,
                m_pos.toPoint(),
                pt,
                size
                );
}

void taskEnemy2::addDamage(int power)
{
    m_damage += power;

    if(m_defence < m_damage)
    {
        if(m_seq == 0)
        {
            int i;
            for(i = 0; i < 8; i++)
                TaskManager::inst()->addTask(new taskExplode(m_pos + QPointF(rand()%64-32, rand()%64-32), 0));

            for(i = 0; i < 2; i++)
            {
                double r = (3.14159 / 180) * (rand() % 360);
                double spd = (rand() % 4 + 1);
                TaskManager::inst()->addEnemyTask(new taskEnemy2(m_pos, 0, QPointF(cos(r)*spd, sin(r)*spd), 1));
            }
        }
        else
        {
           TaskManager::inst()->addTask(new taskExplode(m_pos, 0));
        }

        doDelete();
    }
}

