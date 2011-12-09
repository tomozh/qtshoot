#ifndef JOYSTICK_H
#define JOYSTICK_H
//GetKeyboardState
#include <QtCore/qvector.h>


class Joystick
{
public:
    enum StickDir
    {
        none,
        up,
        up_left,
        left,
        down_left,
        down,
        down_right,
        right,
        up_right,
    };

private:
    Joystick();

public:
    static Joystick* inst()
    {
        static Joystick obj;
        return &obj;
    }

    void pool();
    StickDir getDir() const;
    bool isTrigged(int index) const;

private:
    StickDir        m_dir;
    QVector<bool>   m_trig;
};

#endif // JOYSTICK_H
