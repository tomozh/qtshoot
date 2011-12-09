#include "taskmyship.h"
#include "joystick.h"
#include "texture.h"
#include "taskmanager.h"
#include "taskmybullet.h"
#include "taskexplode.h"
#include "common.h"

taskMyShip::taskMyShip(const QPointF& pt, int zorder)
    : TaskChara(pt, zorder)
    , m_state(START)
    , m_frameCount(0)
    , m_timer(0)
{
    m_size = QSize(8, 8);
    m_power     = 1;
    m_defence   = 1;
    m_damage    = 0;
}

void taskMyShip::oneFrame()
{
    QPointF acc;

    switch(m_state)
    {
    case START:
        if(m_pos.y() <= (SCR_Y - 128))
            m_state = IDLE;
        else
            m_pos += QPointF(0, -2);
        break;

    case IDLE:
        switch(Joystick::inst()->getDir())
        {
        case Joystick::up:            acc = QPointF( 0.0, -1.0);  break;
        case Joystick::up_left:       acc = QPointF(-0.7, -0.7);  break;
        case Joystick::left:          acc = QPointF(-1.0,  0.0);  break;
        case Joystick::down_left:     acc = QPointF(-0.7,  1.0);  break;
        case Joystick::down:          acc = QPointF( 0.0,  1.0);  break;
        case Joystick::down_right:    acc = QPointF( 0.7,  0.7);  break;
        case Joystick::right:         acc = QPointF( 1.0,  0.0);  break;
        case Joystick::up_right:      acc = QPointF( 0.7, -0.7);  break;
        default:                      acc = QPointF( 0.0,  0.0);  break;
        }

        acc *= 4.0;
        m_pos += acc;

        if(m_pos.x() < 0)           m_pos.rx() = 0;
        else if(m_pos.x() > SCR_X)  m_pos.rx() = SCR_X;
        if(m_pos.y() < 0)           m_pos.ry() = 0;
        else if(m_pos.y() > SCR_Y)  m_pos.ry() = SCR_Y;

        if(Joystick::inst()->isTrigged(0))
            TaskManager::inst()->addMyTask(new taskMyBullet(m_pos, 0));
        break;

    case CLASH:
        if(m_timer > 120)
        {
            TaskManager::inst()->addMyTask(new taskMyShip(QPointF(SCR_X / 2, SCR_Y), 0));
            doDelete();
        }
        else
        {
            m_timer++;
        }
        break;

    default:
        qWarning("invalid state");
        break;
    }

    TaskManager::inst()->setMyShipPos(m_pos);
}

void taskMyShip::render(QPainter* painter)
{
    if((m_state == START) || (m_state == IDLE))
    {
        if(((m_frameCount & 1) == 0) || (m_state == IDLE))
        {
            Texture::inst()->putSprite(
                        "MAIN",
                        painter,
                        m_pos.toPoint(),
                        QPoint(32, 0),
                        QSize(32, 32)
                        );
        }
    }

    m_frameCount++;
}

void taskMyShip::addDamage(int power)
{
    if(m_state == IDLE)
    {
        m_damage += power;

        if(m_defence < m_damage)
        {
            int i;
            for(i = 0; i < 8; i++)
                TaskManager::inst()->addTask(new taskExplode(m_pos + QPointF(rand()%64-32, rand()%64-32), 0));

            m_timer = 0;
            m_state = CLASH;
        }
    }
}

