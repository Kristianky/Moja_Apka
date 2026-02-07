#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <windows.h>
#include <string>
#include "Mouse.h"

class Button
{
private:
    // Button rectangle and color off rectangle
    RECT Rect;
    COLORREF BtnColor1, BtnColorIn, BtnColorHov;
    // Button Text Size Color
    std::wstring BtnText;
    COLORREF TextColorOff, TextColorOn;
    int TextSize;

public:
    Button();
    ~Button() = default;

    bool InButt, InButtMem;
    void MouseInside(HWND hwnd);
    void MouseClicked(HWND hwnd);
    void DrawBtn(HDC hdc, HWND hwnd); /// Funkcia pre Ui
    void SetRect(int X, int Y, int Lenght, int Width)
    {
        Rect.top = Y;
        Rect.left = X;
        Rect.bottom = Y + Width;
        Rect.right = X + Lenght;
    }
    void SetColor(COLORREF BtnColor1, COLORREF BtnColor2, COLORREF BtnColor3)
    {
        Button::BtnColor1 = BtnColor1;
        BtnColorIn = BtnColor2;
        BtnColorHov = BtnColor3;
    }
    void SetText(std::wstring Text, COLORREF Coloroff, COLORREF Coolloron)
    {
        BtnText = Text;
        TextColorOff = Coloroff;
        TextColorOn = Coolloron;
    }
    void MouseLBtnDown(HWND hwnd);
};

#endif