#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_

#include <windows.h>
#include "Mouse.h"
#include "Ui.h"


class AppDispatcher
{
    private:
      bool Inside_X_Mem;
      bool Inside_Min_Mem;
      bool Inside_Minimize_Mem;
      bool In_Border;
      RECT MainWindow;
      UI Ui;
      VirtualPage *Page;
public:
    
    AppDispatcher(HWND hwnd);
    ~AppDispatcher() = default;
    void MainLayout(RECT &MainWindow);
    void DrawDispatch(HDC hdc, HWND hwnd);
    void CallRedraw_MouseMove(LPARAM lparam, HWND hwnd);
    void CallMouseClick(LPARAM lpram,HWND hwnd);
    void CallMouseLBtnDown(HWND hwnd);
    bool Get_In_Border(){return In_Border;}
    int NCWnchittest(HWND hwnd,LPARAM lparam,WPARAM wparam);
};

#endif