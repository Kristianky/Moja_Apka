#include "Dispatcher.h"

AppDispatcher::AppDispatcher(HWND hwnd) : Ui(hwnd)

{
    Inside_X_Mem = false;
}
// Volanie pre kreslenie vo wmpaint
void AppDispatcher::DrawDispatch(HDC hdc, HWND hwnd)
{
    Ui.Draw_Border(hdc, hwnd);
}
// volanie akcii mysi pre border tlacidla
void AppDispatcher::CallRedraw_MouseMove(LPARAM lparam, HWND hwnd)
{
    //Tlacidlo X
    Ui.Inside_X = Mouse::X > Ui.Main_Window.right - 50 && Mouse::Y < 30;
    //Tlacidlo restore
    Ui.Inside_Minimalize = Mouse::X > Ui.Main_Window.right - 100 && Mouse::X < Ui.Main_Window.right - 50 && Mouse::Y < 30;
    //Tlacidlo Minimize
    Ui.Inside_Minimize = Mouse::X > Ui.Main_Window.right - 150 && Mouse::X < Ui.Main_Window.right - 100 && Mouse::Y < 30;
    // Tlacidlo X Logika pre mys
    if (Ui.Inside_X != Inside_X_Mem)
    {
        Inside_X_Mem = Ui.Inside_X;
        InvalidateRect(hwnd, &Ui.X_Rect, TRUE);
    }
    else if (Inside_X_Mem && !Ui.Inside_X)
    {
        Inside_X_Mem = false;
        InvalidateRect(hwnd, &Ui.X_Rect, TRUE);
    }
    // Tlacidlo Minimalize
    if (Ui.Inside_Minimalize != Inside_Min_Mem)
    {
        Inside_Min_Mem = Ui.Inside_Minimalize;
        InvalidateRect(hwnd, &Ui.Minimalize_Rect, TRUE);
    }
    else if (Inside_Min_Mem && !Ui.Inside_Minimalize)
    {
        Inside_Min_Mem = false;
        InvalidateRect(hwnd, &Ui.Minimalize_Rect, TRUE);
    }
    //Tlacidlo Minimize
     if (Ui.Inside_Minimize != Inside_Minimize_Mem)
    {
        Inside_Minimize_Mem = Ui.Inside_Minimize;
        InvalidateRect(hwnd, &Ui.Minimize_Rect, TRUE);
    }
    else if (Inside_Minimize_Mem && !Ui.Inside_Minimize)
    {
        Inside_Minimize_Mem = false;
        InvalidateRect(hwnd, &Ui.Minimize_Rect, TRUE);
    }
    
}
// volanie pre clickunutie lavym tlacidlo mysi
void AppDispatcher::CallMouseClick(LPARAM lparam, HWND hwnd)
{
    if (Inside_X_Mem && Mouse::LBtn_Clicked)
    {
        PostQuitMessage(0);
    }
    if (Inside_Min_Mem && Mouse::LBtn_Clicked)
    {
        if(IsZoomed(hwnd))
        ShowWindow(hwnd,SW_RESTORE);
        else
        ShowWindow(hwnd,SW_MAXIMIZE);
    }
    if(Inside_Minimize_Mem && Mouse::LBtn_Clicked)
    {
        ShowWindow(hwnd,SW_MINIMIZE);
    }
}
//Volanie vo wm_Lbtndown
void AppDispatcher::CallMouseLBtnDown(HWND hwnd)
{
    if (Inside_X_Mem)
    {
        Inside_X_Mem = Ui.Inside_X;
        InvalidateRect(hwnd, &Ui.X_Rect, TRUE);
    }
    else if (!Ui.Inside_X)
    {
        Inside_X_Mem = false;
        InvalidateRect(hwnd, &Ui.X_Rect, TRUE);
    }
    // Tlacidlo Minimalize
    if (Inside_Min_Mem)
    {
        Inside_Min_Mem = Ui.Inside_Minimalize;
        InvalidateRect(hwnd, &Ui.Minimalize_Rect, TRUE);
    }
    else if (Ui.Inside_Minimalize)
    {
        Inside_Min_Mem = false;
        InvalidateRect(hwnd, &Ui.Minimalize_Rect, TRUE);
    }
    //Tlacidlo Minimize
     if ( Inside_Minimize_Mem)
    {
        Inside_Minimize_Mem = Ui.Inside_Minimize;
        InvalidateRect(hwnd, &Ui.Minimize_Rect, TRUE);
    }
    else if (Ui.Inside_Minimize)
    {
        Inside_Minimize_Mem = false;
        InvalidateRect(hwnd, &Ui.Minimize_Rect, TRUE);
    }
}