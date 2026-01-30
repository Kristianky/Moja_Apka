#include "Dispatcher.h"

AppDispatcher::AppDispatcher(HWND hwnd)
{
    Inside_X_Mem = false;
    Ui(hwnd);
}

void AppDispatcher::DrawDispatch(HDC hdc,HWND hwnd)
{
     Ui.Draw_Border(hdc,hwnd);
}

void AppDispatcher::CallRedraw_MouseMove(HDC hdc,HWND hwnd)
{
    if(Ui.Inside_X != Inside_X_Mem)
    {
       Inside_X_Mem = Ui.Inside_X;
       InvalidateRect(hwnd,&Ui.X_Rect,TRUE);
    }
}