#include "Ui.h"

void UI::Draw_Border(HDC hdc,HWND Main_Hwnd)
{
    RECT Main_Rect;
    GetClientRect(Main_Hwnd,&Main_Rect);
    RECT Border_Rect;
    Border_Rect.left = Main_Rect.left;
    Border_Rect.bottom = Main_Rect.top +10 ;
    Border_Rect.top = Main_Rect.top;
    Border_Rect.right = Border_Rect.right - 30;
    HBRUSH Border_Color = CreateSolidBrush(RGB(30,30,30));
    HBRUSH Border_Hold = (HBRUSH)SelectObject(hdc,Border_Color);
    FillRect(hdc,&Border_Rect,Border_Hold);
    SelectObject(hdc,Border_Hold);
    DeleteObject(Border_Color);
    
}