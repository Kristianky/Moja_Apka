#ifndef _APLICATION_H_
#define _APLICATION_H_

#include <windows.h>
#include "Ui.h"
#include "Mouse.h"
#include "Dispatcher.h"

class Aplication
{
    private:
    static LRESULT CALLBACK WindowProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK WindowProcRedirect(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
    AppDispatcher DispApp;
    public:
    Aplication(HINSTANCE Hinstance);
    ~Aplication();
    HWND Main_Hwnd;
    public:
    //Funkcia pre volanie kreslenia v Ui pre border tlacidla
    void RedrawBorderBTN();

};

#endif
