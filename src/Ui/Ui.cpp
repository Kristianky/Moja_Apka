#include "Ui.h"

UI::UI(HWND hwnd)
{
}

void UI::Draw_Border(HDC hdc, HWND Main_Hwnd)
{
    //Inicializacia velkosti bordera a ziskanie velkosti okna 
    GetClientRect(Main_Hwnd, &Main_Window);
    X_Rect = {Main_Window.right - 50, Main_Window.top, Main_Window.right, Main_Window.top + 30};
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
    if (Inside_X)
    {
        Color_X = CreateSolidBrush(RGB(200, 0, 0));
    }
    else
    {
        Color_X = CreateSolidBrush(RGB(30, 200, 30));
    }
    FillRect(hdc, &X_Rect, Color_X);
    DeleteObject(Color_X);

}