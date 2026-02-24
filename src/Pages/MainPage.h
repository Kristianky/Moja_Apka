#ifndef _MAINPAGE_H_
#define _MAINPAGE_H_

#include <windows.h>
#include "PageVirtual.h"

class MainPage : public VirtualPage
{
private:
    RECT MainWindow;

public:
    MainPage(HWND hwnd);
    Button BtnConnect;
    Button BtnConnectAndSend;
    Edit EditSend;
    virtual void Btn_Redraw_Call(HWND hwnd) override;
    virtual int Page_Num() override { return 0; };
    virtual void Btn_Draw(HDC hdc, HWND hwnd,RECT &MainRect) override;
    virtual void SetMainWindow(RECT &MainRect) override {MainWindow = MainRect;}
    virtual void LBtnDown(HWND hwnd) override;
};

#endif