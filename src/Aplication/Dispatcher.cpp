#include "Dispatcher.h"

AppDispatcher::AppDispatcher(HWND hwnd):Ui(hwnd)

{
    Inside_X_Mem = false;
}

void AppDispatcher::DrawDispatch(HDC hdc,HWND hwnd)
{
     Ui.Draw_Border(hdc,hwnd);
}

void AppDispatcher::CallRedraw_MouseMove(LPARAM lparam,HWND hwnd)
{
    Ui.Inside_X = Mouse::X > Ui.Main_Window.right - 50 && Mouse::Y < 30;
    
    if(Ui.Inside_X != Inside_X_Mem)
    {
       Inside_X_Mem = Ui.Inside_X;
       InvalidateRect(hwnd,&Ui.X_Rect,TRUE);
    }
    else if (Inside_X_Mem && !Ui.Inside_X)
    {
        Inside_X_Mem = false;
        InvalidateRect(hwnd,&Ui.X_Rect,TRUE);
    }
}