#include "MainPage.h"

MainPage::MainPage(HWND hwnd,RECT &MainRect)
: MainWindow{MainRect},BtnConnect(MainRect.left + 10,MainRect.top + 100,100,500,RGB(0,0,50),RGB(200,200,200),L"Connect")
{
   
}

void MainPage::Btn_Redraw_Call(HWND hwnd)
{
     BtnConnect.MouseInside(hwnd);
}

void MainPage::Btn_Draw(HDC hdc,HWND hwnd)
{
    BtnConnect.DrawBtn(hdc,hwnd);
}