#pragma once
#include "Object.h"

class Image;
class Unit :
	public Object
{
private:
	Image* m_pImage;
	int m_iAttackPower;   //공격력
	float m_iAttackSpeed; //1초에 몇번 공격하는가

public:
	Unit();
	~Unit();
private:
	void Attack();
	CLONE(Unit);
public:
	void Update() override;
	void Render(HDC _dc) override;
};

