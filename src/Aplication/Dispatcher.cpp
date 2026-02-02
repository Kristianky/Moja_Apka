#include "Dispatcher.h"

AppDispatcher::AppDispatcher(HWND hwnd):Ui(hwnd)

{
    Inside_X_Mem = false;
}
//Volanie pre kreslenie vo wmpaint
void AppDispatcher::DrawDispatch(HDC hdc,HWND hwnd)
{
     Ui.Draw_Border(hdc,hwnd);
}
//volanie akcii mysi pre border tlacidla
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
//volanie pre clickunutie lavym tlacidlo mysi
void AppDispatcher::CallMouseClick(LPARAM lparam,HWND hwnd)
{
    if(Ui.Inside_X && Mouse::LBtn_Clicked)
    {
        
    }
}