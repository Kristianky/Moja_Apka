#ifndef _EDIT_H_
#define _EDIT_H_

#include <windows.h>
#include "Mouse.h"
#include <string>

class Edit
{
private:
    RECT Rect;
    COLORREF EditColor, BorderColor, TextColor;
    std::wstring Text;
    int Width,Lenght,TextSize;

public:
    Edit();
    ~Edit() = default;
    void SetRect(int X, int Y, int Lenght, int Width)
    {
        Rect.left = X;
        Rect.right = X + Lenght;
        Rect.top = Y;
        Rect.bottom = Y + Width;
        Edit::Width = Width;
        Edit::Lenght = Lenght;
    }
    void SetTextColor(COLORREF TextClr){TextColor = TextClr;}
    void SetEditColor(COLORREF EditClr,COLORREF TextClr){EditColor = EditClr;TextColor = TextClr;}
    void DrawEdit(HWND hwnd,HDC hdc);
};

#endif