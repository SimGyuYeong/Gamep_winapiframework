#include "pch.h"
#include "Unit.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"

Unit::Unit() :
	m_iAttackPower(5),
	m_iAttackSpeed(1)
{
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"", L"");

	CreateAnimator();
	//공격 애니메이션 생성
	GetAnimator()->CreateAnimation(L"UnitAttack", pImg, Vec2(0.f, 0.f), Vec2(0.f, 0.f), Vec2(0.f, 0.f), 0, 0.f);
}

Unit::~Unit()
{
}

void Unit::Attack()
{
	GetAnimator()->Play(L"UnitAttack", false);
	//TODO: Unit Bullet 생성
}

void Unit::Update()
{
    //적이 공격거리 안에 들어오면
	if (1)
	{
		Attack();
	}
}

void Unit::Render(HDC _dc)
{
	Component_Render(_dc);
}
