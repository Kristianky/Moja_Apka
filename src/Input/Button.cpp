#include "Button.h"
Button::Button(int posX,int posY,int width,int lenght,COLORREF BtnClr,COLORREF TextClr,std::wstring Text)
    : PosX{posX},PosY{posY},Width{posY + width},Lenght{posX + lenght},BtnColor{BtnClr},TextColor{TextClr},BtnText{Text}
{
   InButt = false;
   InButtMem = false;
}

void Button::MouseInside(HWND hwnd)
{
   RECT Butt = {PosX,PosY,Lenght,Width};
   if (InButt != InButtMem)
   {
      InButtMem = InButt;
      InvalidateRect(hwnd, &Butt, TRUE);
   }
   if (InButtMem && !InButt)
   {
      InButtMem = false;
      InvalidateRect(hwnd, &Butt, true);
   }
}

void Button::DrawBtn(HDC hdc, HWND hwnd)
{
   RECT Butt;
   Butt.top = PosY;
   Butt.left = PosX;
   Butt.right = Lenght;
   Butt.bottom = Width;
   HBRUSH Color;
   if (InButtMem)
   {
      Color = CreateSolidBrush(BtnColor);
   }
   else
   {
      Color = CreateSolidBrush(RGB(200,0,0));
   }
   FillRect(hdc, &Butt, Color);
   DeleteObject(Color);
}