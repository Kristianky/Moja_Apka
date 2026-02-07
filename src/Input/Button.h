#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <windows.h>
#include <string>
#include "Mouse.h"



class Button
{
    private:
    RECT Rect;
    public:
    Button();
    ~Button() = default;
    COLORREF BtnColor;
    COLORREF TextColor;
    std::wstring BtnText;
    bool InButt,InButtMem;
    void MouseInside(HWND hwnd);
    void MouseClicked(HWND hwnd);
    void DrawBtn(HDC hdc,HWND hwnd);   ///Funkcia pre Ui
    void SetRect(int X,int Y,int Lenght,int Width){Rect.top = Y;Rect.left = X;Rect.bottom = Y + Width;Rect.right = X + Lenght;}
};

#endif