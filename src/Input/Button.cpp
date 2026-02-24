#include "Button.h"
Button::Button()
{
   // Bools for mouse
   InButt = false;
   InButtMem = false;
   // Color OFf Button
   BtnColor1 = RGB(180, 180, 180);
   BtnColorIn = RGB(100, 100, 100);
   BtnColorHov = RGB(50, 50, 50);
   // Text Button
   BtnText = L"\0";
   TextColorOff = RGB(0, 0, 0);
   TextColorOn = RGB(100, 200, 100);
   TextSize = 10;

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
   if (InButt && Mouse::LBtn_Down)
   {
      InvalidateRect(hwnd, &Rect, true);
   }
}

void Button::DrawBtn(HDC hdc, HWND hwnd)
{
   HBRUSH Color;
   if (InButtMem && !Mouse::LBtn_Down)
   {
      Color = CreateSolidBrush(BtnColorIn);
   }
   else if (InButtMem && Mouse::LBtn_Down)
   {
      Color = CreateSolidBrush(BtnColorHov);
   }
   else
   {
      Color = CreateSolidBrush(BtnColor1);
   }
   FillRect(hdc, &Rect, Color);
   DeleteObject(Color);

   HPEN Pen = CreatePen(PS_SOLID, 3, RGB(50, 50, 50));
   HPEN olDPen = (HPEN)SelectObject(hdc, Pen);
   SelectObject(hdc, GetStockObject(NULL_BRUSH));
   Rectangle(hdc, Rect.left, Rect.top, Rect.right, Rect.bottom);
   SelectObject(hdc, olDPen);
   DeleteObject(Pen);

   if (BtnText != L"\0")
   {
      HFONT HoldFont;
      HFONT Font = (HFONT)CreateFontW(TextSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, L"Segoe UI");
      HoldFont = (HFONT)SelectObject(hdc, &Font);
      if (InButtMem && !Mouse::LBtn_Down)
      {
         SetTextColor(hdc, TextColorOn);
      }
      else if (InButtMem && Mouse::LBtn_Down)
      {
         SetTextColor(hdc, TextColorOn);
      }
      else
      {
         SetTextColor(hdc, TextColorOff);
      }
      SetBkMode(hdc, TRANSPARENT);
      DrawTextW(hdc, BtnText.c_str(), -1, &Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
      DeleteObject(Color);
   }
}

void Button::MouseLBtnDown(HWND hwnd)
{
   if (InButt)
   {
      InvalidateRect(hwnd, &Rect, false);
   }
}

Button Button::operator=(const Button &Rhs)
{
   if(&Rhs == this)
   {
      return *this;
   }
   //Copyrovanie Nastaveni
   BtnColor1 = Rhs.BtnColor1;
   BtnColorHov = Rhs.BtnColorHov;
   BtnColorIn = Rhs.BtnColorIn;
   Width = Rhs.Width;
   Lenght = Rhs.Lenght;

   Rect = Rhs.Rect;
   if(Rect.bottom != 1150)
   {
      Rect.top = Rect.top + Width;
      Rect.bottom = Rect.bottom + Width;
   }

   TextColorOff = Rhs.TextColorOff;
   TextColorOn = Rhs.TextColorOn;
   BtnText = Rhs.BtnText;
   TextSize = Rhs.TextSize;
   return *this;
   
}