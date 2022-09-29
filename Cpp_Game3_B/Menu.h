#pragma once
#include "Scene.h"

class Menu : public Scene
{
private:
	int Cursor;
	char* Buffer[32];
	ULONGLONG Time;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Menu();
	virtual ~Menu();
};

