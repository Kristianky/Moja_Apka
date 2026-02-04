#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <windows.h>
#include <string>
#include "Mouse.h"


class Button
{
    public:
    Button(RECT Rect,COLORREF BtnClr,COLORREF TextClr,std::wstring Text);
    ~Button() = default;
    RECT ButtonRect;
    COLORREF BtnColor;
    COLORREF TextColor;
    std::wstring BtnText;
    bool InButt,InButtMem;
    void MouseInside(HWND hwnd);
    void MouseClicked(HWND hwnd);
    void DrawBtn(HDC hdc,HWND hwnd);   ///Funkcia pre Ui
};

#endif