#pragma once
#include "Object.h"

class Player : public Object
{
private:
	string Texture[8];
	bool Temp;
	int T;
	ULONGLONG Delay;
	ULONGLONG Reload;
	bool Spike;
	int Buff;
	ULONGLONG BuffTime;
	bool PowerUp;
	int Armor;
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Player(*this); }
public:
	void SetIndex(int _Index) { Index = _Index; }
	void SetBuff(int _Buff) { Buff = _Buff; }
	void ReduceArmor(int _Value) { Armor -=  _Value; }
	void SetSpike(bool _Spike) { Spike = _Spike; }
	float GetSpeed() { return Speed; }
	int GetBuff() { return Buff; }
	int GetArmor() { return Armor; }
public:
	Player();
	Player(Transform _Info) : Object(_Info) {};
	virtual ~Player();
};

