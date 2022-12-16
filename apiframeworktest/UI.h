#pragma once
#include "Object.h"
#include "BWindow.h"

class UI : public Object
{
private:
	wstring m_strBtnText;
	wstring const m_strBtn = L"BUTTON";
public:
	UI();
	~UI();
public:
	void Update() override;
	void Render(HDC _dc) override;
};

