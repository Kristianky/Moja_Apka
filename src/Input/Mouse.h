#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <windows.h>

class Mouse
{
public:
    inline static short X;
    inline static short Y;
    // Premenne pre tlacidla mysi
    inline static bool LBtn_Down;
    inline static bool LBtn_Up;
    inline static bool LBtn_Clicked;
    // Static funckie pre ukony s mysou
    static void UpdateX_Y(LPARAM lparam);
    static void Button_L_Button_Down();
    static void Button_L_Button_Up();
    static void Button_L_Clicked();
};

#endif