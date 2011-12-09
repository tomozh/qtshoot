#include "view.h"
#include <math.h>
#include "common.h"
#include "texture.h"
#include "joystick.h"
#include "taskmanager.h"
#include "taskmain.h"

View::View(QWidget *parent) : QGLWidget(parent)
{
    setFixedSize(SCR_X, SCR_Y);
    setAutoFillBackground(false);

    updateTimerId = startTimer(1000/60);
    fpsTimerId = startTimer(1000);
    frameCount = 0;
    fps = 0;

    TaskManager::inst()->addTask(new taskMain());
}

View::~View()
{
    killTimer(updateTimerId);
}

void View::timerEvent(QTimerEvent* event)
{
    if(event->timerId() == fpsTimerId)
    {
        // フレームカウンタリセット
        fps = frameCount;
        frameCount = 0;
    }
    else if(event->timerId() == updateTimerId)
    {
        // メイン処理        
        Joystick::inst()->pool();
        TaskManager::inst()->oneFrame();
        repaint();

        frameCount++;
    }
    else
    {
        QGLWidget::timerEvent(event);
    }
}

//! デバッグ表示
void View::renderDebug(QPainter* painter)
{
    painter->setBackgroundMode(Qt::OpaqueMode);
    painter->drawText(32, 32,
                      tr("%1 fps / %2 tasks")
                     .arg(fps)
                     .arg(TaskManager::inst()->getTaskCount())
                     );

}

void View::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    TaskManager::inst()->render(&painter);
    renderDebug(&painter);

}
