#pragma once
#include "Scene.h"
#include "BWindow.h"
class Scene_Enhance :
	public Scene
{
public:
	Scene_Enhance();
	virtual ~Scene_Enhance();
public:
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update() override;
};

