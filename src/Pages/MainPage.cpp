#include "MainPage.h"

MainPage::MainPage(HWND hwnd)

{
}

void MainPage::Btn_Redraw_Call(HWND hwnd)
{
    BtnConnect.MouseInside(hwnd);
}

void MainPage::Btn_Draw(HDC hdc, HWND hwnd,RECT &Rect)
{
    MainPage::SetMainWindow(Rect);
    //Kreslenie ButtonConnect a nastavenie farieb atd

    BtnConnect.SetRect(MainWindow.left + 50,MainWindow.top + 50,200,100);
    BtnConnect.SetText(L"Connect",RGB(0,0,0),RGB(0,100,0));
    BtnConnect.DrawBtn(hdc, hwnd);
}

void MainPage::LBtnDown(HWND hwnd)
{
    
}