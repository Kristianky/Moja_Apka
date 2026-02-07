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
    BtnConnect.SetRect(MainWindow.left + 50,MainWindow.top + 50,200,100);
    BtnConnect.DrawBtn(hdc, hwnd);
}