#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
private:
	vector<Object*> pSkillList;
	char* Texture[8];
	int Count;
	int Spd;
	int Score;
	int SkillGauge1;
	int SkillGauge2;
	ULONGLONG Respawn;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage();
	virtual ~Stage();
};

