#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_

#include <windows.h>
#include "Mouse.h"
#include "Ui.h"

class AppDispatcher
{
    private:
      bool Inside_X_Mem;
      UI Ui;
public:
    AppDispatcher(HWND hwnd);
    ~AppDispatcher() = default;

    void DrawDispatch(HDC hdc, HWND hwnd);
    void CallRedraw_MouseMove(LPARAM lparam, HWND hwnd);
};

#endif