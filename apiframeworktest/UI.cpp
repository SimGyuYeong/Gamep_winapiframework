#include "pch.h"
#include "UI.h"

UI::UI()
	
{

}

UI::~UI()
{

}

void UI::Update()
{

}

void UI::Render(HDC _dc)
{

    BWindow* bwindow;
    HWND buttonTest = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"OK",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        10,         // x position 
        10,         // y position 
        100,        // Button width
        100,        // Button height
        bwindow->GetWndHandle(),
        NULL,
        (HINSTANCE)GetWindowLongPtr(bwindow->GetWndHandle(), GWLP_HINSTANCE),
        NULL);
}
