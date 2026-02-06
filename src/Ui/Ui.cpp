#include "Ui.h"

UI::UI(HWND hwnd)
{
}

void UI::Draw_Border(HDC hdc, HWND Main_Hwnd)
{
    // Inicializacia velkosti bordera a ziskanie velkosti okna
    GetClientRect(Main_Hwnd, &Main_Window);
    X_Rect = {Main_Window.right - 50, Main_Window.top, Main_Window.right, Main_Window.top + 30};
    Minimalize_Rect = {Main_Window.right - 100, Main_Window.top, Main_Window.right - 50, Main_Window.top + 30};
    Minimize_Rect = {Main_Window.right - 150, Main_Window.top, Main_Window.right - 100, Main_Window.top + 30};
    Border = {0, 0, Main_Window.right - 150, 30};
    // Kreslenie listy
    HBRUSH Border_Color = CreateSolidBrush(RGB(30, 30, 30));
    FillRect(hdc, &Border, Border_Color);
    DeleteObject(Border_Color);
    // Vypisanie nazvu apky do listy
    HFONT BorderFont = CreateFontW(25, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, L"Segoe UI");
    HFONT HoldFont = (HFONT)SelectObject(hdc, BorderFont);
    SetTextColor(hdc, RGB(200, 200, 200));
    SetBkMode(hdc, TRANSPARENT);
    TextOutW(hdc, 10, 2, L"SiemensApp", 11);
    SelectObject(hdc, HoldFont);
    // Vykreslenie border tlacitok
    // X
    HBRUSH Color_X;
    if (Inside_X && !Mouse::LBtn_Down)
    {
        Color_X = CreateSolidBrush(RGB(200, 0, 0));
    }
    else if (Inside_X && Mouse::LBtn_Down)
    {
        Color_X = CreateSolidBrush(RGB(100, 0, 0));
    }
    else
    {
        Color_X = CreateSolidBrush(RGB(30, 30, 30));
    }
    FillRect(hdc, &X_Rect, Color_X);
    DeleteObject(Color_X);
    // Vypisanie X do tlacidla
    HoldFont = (HFONT)SelectObject(hdc, BorderFont);
    SetTextColor(hdc, RGB(255, 255, 255));
    SetBkMode(hdc, TRANSPARENT);
    TextOutW(hdc, Main_Window.right - 30, Main_Window.top + 2, L"X", 1);
    SelectObject(hdc, HoldFont);
    // Vytvorenie tlacidla Minimalize
    HBRUSH Color_Min;
    if (Inside_Minimalize && !Mouse::LBtn_Down)
    {
        Color_Min = Color_Min = CreateSolidBrush(RGB(90, 90, 90));
    }
    else if (Inside_Minimalize && Mouse::LBtn_Down)
    {
        Color_Min = Color_Min = CreateSolidBrush(RGB(200, 200, 200));
    }
    else
    {
        Color_Min = CreateSolidBrush(RGB(30, 30, 30));
    }
    FillRect(hdc, &Minimalize_Rect, Color_Min);
    DeleteObject(Color_Min);
    // Vypisanie Minimalize
    HoldFont = (HFONT)SelectObject(hdc, BorderFont);
    SetTextColor(hdc, RGB(255, 255, 255));
    SetBkMode(hdc, TRANSPARENT);
    if (IsZoomed(Main_Hwnd))
        TextOutW(hdc, Main_Window.right - 80, 2, L"\u2750", 2);
    else
        TextOutW(hdc, Main_Window.right - 80, 2, L"\u25A1", 2);
    // Vytvorenie tlacidla Minimize
    HBRUSH Color_Minize;
    if (Inside_Minimize)
    {
        if (!Mouse::LBtn_Down)
            Color_Minize = CreateSolidBrush(RGB(90, 90, 90));
        else
            Color_Minize = CreateSolidBrush(RGB(140, 0, 0));
    }
    else
    {
        Color_Minize = CreateSolidBrush(RGB(30, 30, 30));
    }
    FillRect(hdc, &Minimize_Rect, Color_Minize);
    DeleteObject(Color_Minize);
    // Vypisanie Minimize
    HoldFont = (HFONT)SelectObject(hdc, BorderFont);
    SetTextColor(hdc, RGB(255, 255, 255));
    SetBkMode(hdc, TRANSPARENT);
    TextOutW(hdc, Main_Window.right - 130, 2, L"\u2500", 2);
}

void UI::Draw_Pages(HDC hdc,HWND hwnd,VirtualPage *Page)
{

        Page->Btn_Draw(hdc,hwnd);
    
}