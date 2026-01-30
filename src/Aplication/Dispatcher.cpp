#include "Dispatcher.h"

void AppDispatcher::DrawDispatch(HDC hdc,HWND hwnd)
{
     UI::Draw_Border(hdc,hwnd);
}

void AppDispatcher::CallRedraw_MouseMove(HDC hdc,HWND hwnd)
{
    bool Inside_X = Mouse::X > Main_Window.right - 50 && Mouse::Y < 30;
}