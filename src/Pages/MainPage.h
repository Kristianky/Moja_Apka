#ifndef _MAINPAGE_H_
#define _MAINPAGE_H_

#include <windows.h>
#include "Mouse.h"
#include "Button.h"
#include "PageVirtual.h"

class MainPage:VirtualPage
{
    private:
    public:
    RECT MainWindow;
    MainPage(HWND hwnd,RECT MainRect);
    Button BtnConnect;

};

#endif