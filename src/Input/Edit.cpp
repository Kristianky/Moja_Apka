#include "Edit.h"
Edit::Edit()
{
   TextColor = RGB(0,0,0);
   EditColor = RGB(200,200,200);
   BorderColor = RGB(50,50,50);
   TextSize = 10;
   Text = L"\0";
}
void Edit::DrawEdit(HWND hwnd,HDC hdc)
{
     HBRUSH Color = CreateSolidBrush(EditColor);
     FillRect(hdc,&Rect,Color);
     DeleteObject(Color);
     HPEN BorderClr = CreatePen(PS_SOLID,3,BorderColor);
     HPEN OldPen = (HPEN)SelectObject(hdc,BorderClr);
     SelectObject(hdc,GetStockObject(NULL_BRUSH));
     Rectangle(hdc,Rect.left,Rect.top,Rect.right,Rect.bottom);
     SelectObject(hdc,OldPen);
     DeleteObject(BorderClr);

}