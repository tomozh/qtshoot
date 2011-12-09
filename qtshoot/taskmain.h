#ifndef TASKMAIN_H
#define TASKMAIN_H

#include "task.h"

class QPainter;
class taskMain : public Task
{
public:
    taskMain();

    virtual void oneFrame();
    virtual void render(QPainter* painter);

private:
//    QPixmap m_img;
    int m_frameCount;
};

#endif // TASKMAIN_H
