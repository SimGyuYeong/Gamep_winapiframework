#include "pch.h"
#include "Scene_Fight.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include <random>
#include "TimeMgr.h"
#include "ResMgr.h"

void Scene_Fight::Enter()
{
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"FightBackground", L"Image\\FightSceneBackground.bmp");

	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");

	float grid = Core::GetInst()->GetResolution().y / 5;
	for (int i = 0; i < 5; i++)
	{
		spawnY[i] = (grid * i + grid * (i + 1)) / 2;
	}

	// Object 추가
	Player* pObj = new Player;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	// 충돌 지정 
	// Player - Monster 그룹 간의 충돌 체크
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);

	startTime = TimeMgr::GetInst()->GetTime();
	startTime += delay;
}

void Scene_Fight::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Fight::Update()
{
	Scene::Update();

	float fTime = TimeMgr::GetInst()->GetTime();

	if (startTime == fTime)
	{
		Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
		int iMonster = 5;
		float fMoveDist = 25.f;
		float fObjScale = 50.f;

		random_device rd;  //Will be used to obtain a seed for the random number engine
		mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		uniform_int_distribution<> dis(0, 4);

		Monster* pMonsterObj = new Monster;
		pMonsterObj->SetName(L"Monster");
		pMonsterObj->SetPos(Vec2(vResolution.x, spawnY[dis(gen)]));
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMoveDistance(fMoveDist);
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);

		startTime += delay;
	}

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}

Scene_Fight::Scene_Fight()
{
}

Scene_Fight::~Scene_Fight()
{
}
