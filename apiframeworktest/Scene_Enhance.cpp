#include "pch.h"
#include "Scene_Enhance.h"

Scene_Enhance::Scene_Enhance()
{
}

Scene_Enhance::~Scene_Enhance()
{
}

void Scene_Enhance::Enter()
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

void Scene_Enhance::Exit()
{

}

void Scene_Enhance::Update()
{

}
