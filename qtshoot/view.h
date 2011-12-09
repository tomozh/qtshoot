#ifndef VIEW_H
#define VIEW_H

#include <QtGui>
#include <QGLWidget>

class View : public QGLWidget
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);
    ~View();

signals:

public slots:

private:
    virtual void paintEvent(QPaintEvent* event);
    virtual void timerEvent(QTimerEvent* event);

    void renderDebug(QPainter* painter);

    int updateTimerId;
    int fpsTimerId;
    int frameCount;
    int objectCount;
    int fps;
};

#endif // VIEW_H
