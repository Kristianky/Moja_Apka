#include "Button.h"
Button::Button()
{
   InButt = false;
   InButtMem = false;
}

void Button::MouseInside(HWND hwnd)
{
   InButt = Mouse::X > Rect.left && Mouse::X < Rect.right && Mouse::Y > Rect.top && Mouse::Y < Rect.bottom;
   if (InButt != InButtMem)
   {
      InButtMem = InButt;
      InvalidateRect(hwnd, &Rect, TRUE);
   }
   if (InButtMem && !InButt)
   {
      InButtMem = false;
      InvalidateRect(hwnd, &Rect, true);
   }
}

void Button::DrawBtn(HDC hdc, HWND hwnd)
{

   HBRUSH Color;
   if (InButtMem)
   {
      Color = CreateSolidBrush(RGB(100,100,100));
   }
   else
   {
      Color = CreateSolidBrush(RGB(180,180,180));
   }
   FillRect(hdc, &Rect, Color);
   DeleteObject(Color);
}