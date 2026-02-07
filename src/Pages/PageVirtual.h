#ifndef _PAGEVIRTUAL_H_
#define _PAGEVIRTUAL_H_

#include<windows.h>

class VirtualPage
{
private:
public:
    VirtualPage() {};
    ~VirtualPage() = default;
    virtual void Btn_Redraw_Call(HWND hwnd) = 0;
    virtual int Page_Num() = 0;
    virtual void Btn_Draw(HDC hdc,HWND hwnd,RECT &MainRect) = 0;
    virtual void SetMainWindow(RECT &MainRect) = 0;
};

#endif