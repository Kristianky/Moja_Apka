#ifndef _UI_H_
#define _UI_H_

#include <windows.h>
#include "Mouse.h"

class UI
{
public:
   UI(HWND hwnd);
   void Draw_Border(HDC hdc,HWND Main_Hwnd);
   //Rect pre jednotlive tlacidla na borderi
   RECT Main_Window; //HL okno apky
   RECT X_Rect;
   RECT Minimalize_Rect;
   RECT Border;
   bool Inside_X;
   bool Inside_Minimalize;

};

#endif