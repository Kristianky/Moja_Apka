#include "Button.h"
Button::Button(RECT Rect, COLORREF BtnClr, COLORREF TextClr, std::wstring Text)
    : ButtonRect{Rect}, BtnColor{BtnClr}, TextColor{TextClr}, BtnText{Text}
{
   InButt = false;
   InButtMem = false;
}

void Button::MouseInside(HWND hwnd)
{
   InButt = Mouse::X < ButtonRect.right && Mouse::X > ButtonRect.left && Mouse::Y < ButtonRect.bottom && Mouse::Y > ButtonRect.top;
   if (InButt != InButtMem)
   {
      InButtMem = InButt;
      InvalidateRect(hwnd, &ButtonRect, TRUE);
   }
   if (InButtMem && !InButt)
   {
      InButtMem = false;
      InvalidateRect(hwnd, &ButtonRect, true);
   }
}

void Button::DrawBtn(HDC hdc, HWND hwnd)
{
   HBRUSH Color;
   if (InButtMem)
   {
      Color = CreateSolidBrush(BtnColor);
   }
   else
   {
      Color = CreateSolidBrush(RGB(200,0,0));
   }
   FillRect(hdc, &ButtonRect, Color);
   DeleteObject(Color);
}