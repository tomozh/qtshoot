#include "joystick.h"
#include "windows.h"

#define MAX_TRIGGERS    2


Joystick::Joystick()
    : m_dir(none)
{
    m_trig.resize(MAX_TRIGGERS);
}

void Joystick::pool()
{
    bool    upKey;
    bool    downKey;
    bool    leftKey;
    bool    rightKey;

    upKey       = (::GetAsyncKeyState(VK_UP) != 0);
    downKey     = (::GetAsyncKeyState(VK_DOWN) != 0);
    leftKey     = (::GetAsyncKeyState(VK_LEFT) != 0);
    rightKey    = (::GetAsyncKeyState(VK_RIGHT) != 0);

    if     (upKey && leftKey)     m_dir = up_left;
    else if(upKey && rightKey)    m_dir = up_right;
    else if(downKey && leftKey)   m_dir = down_left;
    else if(downKey && rightKey)  m_dir = down_right;
    else if(upKey)                m_dir = up;
    else if(downKey)              m_dir = down;
    else if(leftKey)              m_dir = left;
    else if(rightKey)             m_dir = right;
    else                          m_dir = none;

    m_trig[0]   = (::GetAsyncKeyState('Z') != 0);
    m_trig[1]   = (::GetAsyncKeyState('X') != 0);
}

Joystick::StickDir Joystick::getDir() const
{
    return m_dir;
}

bool Joystick::isTrigged(int index) const
{
    if(index >= m_trig.count())
        return  false;

    return m_trig[index];
}

