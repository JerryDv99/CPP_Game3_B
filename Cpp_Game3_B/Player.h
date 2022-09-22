#pragma once
#include "Object.h"

class Player : public Object
{
private:
	string Texture[8];
	int Index;
	bool Temp;
	int T;
	ULONGLONG Delay;
	ULONGLONG Reload;
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Player(*this); }
public:
	void SetIndex(int _Index) { Index = _Index; }
	float GetSpeed() { return Speed; }
public:
	Player();
	Player(Transform _Info) : Object(_Info) {};
	virtual ~Player();
};

