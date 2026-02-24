#ifndef _UI_H_
#define _UI_H_

#include <windows.h>
#include "Mouse.h"
#include "MainPage.h"

class UI
{
private:
   RECT Main_Window;

public:
   UI(HWND hwnd);
   void Draw_Border(HDC hdc, HWND Main_Hwnd);
   void Draw_Pages(HDC hdc, HWND hwnd, VirtualPage *Page);
   // Rect pre jednotlive tlacidla na borderi
   RECT X_Rect;
   RECT Minimalize_Rect;
   RECT Minimize_Rect;
   RECT Border;
   bool Inside_X;
   bool Inside_Minimalize;
   bool Inside_Minimize;
   void Set_MainWindow(RECT &MainRect){Main_Window = MainRect;}
};

#endif