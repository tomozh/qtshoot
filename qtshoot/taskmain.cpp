#include "taskmain.h"

#include "common.h"
#include "texture.h"
#include "joystick.h"
#include "taskmanager.h"

#include "taskmyship.h"
#include "taskenemy1.h"
#include "taskenemy2.h"
#include "taskbg.h"


taskMain::taskMain()
    : m_frameCount(0)
{
    Texture::inst()->loadTexture("MAIN", "../img/edge1.png");

    TaskManager::inst()->addTask(new taskBG(0));
    TaskManager::inst()->addMyTask(new taskMyShip(QPointF(SCR_X / 2, SCR_Y), 0));
}

void taskMain::oneFrame()
{
    if((m_frameCount % 60) == 0)
        TaskManager::inst()->addEnemyTask(new taskEnemy1(QPointF(rand() % SCR_X, -16), 0, QPointF(0, 2)));

    if((m_frameCount % 120) == 0)
        TaskManager::inst()->addEnemyTask(new taskEnemy2(QPointF(rand() % SCR_X, -16), 0, QPointF(rand() % 4 - 2, rand() % 2 + 1), 0));

    m_frameCount++;
}

void taskMain::render(QPainter* painter)
{
}
