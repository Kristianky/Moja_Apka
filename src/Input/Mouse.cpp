#include "Mouse.h"

void Mouse::UpdateX_Y(LPARAM lparam)
{
    X = static_cast<short>(lparam & 0xFFFF);
    Y = static_cast<short>((lparam >> 16) & 0xFFFF);
}

void Mouse::Button_L_Button_Down()
{
    LBtn_Down = true;
    LBtn_Up = false;
    LBtn_Clicked = false;
}

void Mouse::Button_L_Button_Up()
{
    LBtn_Down = false;
    LBtn_Up = true;
    LBtn_Clicked = false;
}

void Mouse::Button_L_Clicked()
{
    if (LBtn_Down)
    {
        LBtn_Clicked = true;
    }
}