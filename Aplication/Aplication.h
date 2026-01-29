#ifndef _APLICATION_H_
#define _APLICATION_H_

#include <windows.h>
#include "Ui.h"

class Aplication
{
    private:
    static LRESULT CALLBACK WindowProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK WindowProcRedirect(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
    public:
    Aplication(HINSTANCE Hinstance);
    ~Aplication();
    HWND Main_Hwnd;

};

#endif
