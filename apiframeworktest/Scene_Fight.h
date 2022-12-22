#pragma once
#include "Scene.h"
class Scene_Fight :
    public Scene
{
public:
    Scene_Fight();
    virtual ~Scene_Fight();

public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;

private:
    float spawnY[5];
    float startTime;
    float delay = 2.0f;
};

