#include "Aplication.h"

Aplication::Aplication(HINSTANCE Hinstance) : DispApp(Main_Hwnd)
{
    const wchar_t CLASSNAME[] = L"MojeOknoTrieda"; // Tu si mozme nastavit hlavicku okna
    WNDCLASSW wc{};                                // vytvorenie classy appky
    wc.lpfnWndProc = Aplication::WindowProcSetup;  // ukaze na funkciu ktoru sme si hore zadefinovali
    wc.hInstance = Hinstance;                      // priraduje handle
    wc.lpszClassName = CLASSNAME;                  // priradi meno okna
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 5); // nastavi styl a farbu okna
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);      // nacita kurzor a nastavi styl
    RegisterClassW(&wc);                           // regitruje classu do windows az po tomto kroku mozme vytvorit okno

    Main_Hwnd = CreateWindowExW( // vytvorenie hl okna
        0,
        CLASSNAME,
        L"Moja Appka",
        WS_POPUP,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 250,
        NULL, NULL, Hinstance, this);
    ShowWindow(Main_Hwnd, SW_SHOW);
    UpdateWindow(Main_Hwnd);
}
Aplication::~Aplication()
{
}

LRESULT Aplication::WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)

{
    switch (umsg)
    {
    case WM_CREATE:
    {
        GetClientRect(hwnd,&MainWindow);
        DispApp.MainLayout(MainWindow);
       
        break;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    case WM_NCHITTEST:
    {
        return HTCLIENT;
    }
    case WM_PAINT:
    {
        PAINTSTRUCT Ps;
        HDC hdc = BeginPaint(hwnd, &Ps);
        DispApp.DrawDispatch(hdc, hwnd);
        EndPaint(hwnd, &Ps);
        break;
    }
    case WM_SIZE:
    {
        GetClientRect(hwnd, &MainWindow);
        switch (wparam)
        {
        case SIZE_MINIMIZED:
        {
            InvalidateRect(hwnd, &MainWindow, TRUE);
        }
        case SIZE_MAXIMIZED:
        {
            InvalidateRect(hwnd, &MainWindow, TRUE);
        }
        case SIZE_RESTORED:
        {
            InvalidateRect(hwnd, &MainWindow, TRUE);
        }
        }
        DispApp.MainLayout(MainWindow);
        break;
    }
    case WM_MOUSEMOVE:
    {
        Mouse::UpdateX_Y(lparam);
        DispApp.CallRedraw_MouseMove(lparam, hwnd);
        break;
    }
    case WM_LBUTTONDOWN:
    {
        Mouse::Button_L_Button_Down();
        DispApp.CallMouseLBtnDown(hwnd);
        break;
    }
    case WM_LBUTTONUP:
    {
        Mouse::Button_L_Clicked();
        DispApp.CallMouseClick(lparam, hwnd);
        Mouse::Button_L_Button_Up();
        break;
    }
    default:
    {
        return DefWindowProc(hwnd, umsg, wparam, lparam);
    }
    }
    return 0;
}
LRESULT CALLBACK Aplication::WindowProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_NCCREATE)
    {                                                                                    // NCCREATE ide este pre CREATE potrebujeme to kvoli this pointru este pred vytvorenim okna
        auto cs = reinterpret_cast<CREATESTRUCT *>(lParam);                              // CREATESTRUCT je funkcia ktora vynika pri vytvarani okna
                                                                                         // cize vtedy potrebujeme z nej dostat pointer aby sme mohli manipulovat s oknom
        auto self = reinterpret_cast<Aplication *>(cs->lpCreateParams);                  // toto ulozi pointer z create struct do nasej appky
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)self);                           // toto ulozi pointer do pamate ktoru ma windows urcenu pre uzivatelov pri vytvarani okien
        SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)&Aplication::WindowProcRedirect); // tu ulozime pointer do urcenej pamate windowsom                                                                  //mozme ptr prepisovat a ukladat ale tato pamat je presne urcena wndproc funkciu
        return self->WindowProc(hwnd, msg, wParam, lParam);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK Aplication::WindowProcRedirect(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    auto self = reinterpret_cast<Aplication *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    return self->WindowProc(hwnd, msg, wParam, lParam);
}
