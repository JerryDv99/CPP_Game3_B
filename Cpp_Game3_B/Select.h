#pragma once
#include "Scene.h"

class SceneManager;
class Select : public Scene
{
private:
	bool Index;
	char* Buffer[64];
	ULONGLONG Time;
	bool Guide;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Select();
	virtual ~Select();
};

