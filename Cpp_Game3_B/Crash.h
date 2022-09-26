#pragma once
#include "Object.h"

class Crash : public Object
{
private:
	char* Texture[8];
	int Count;
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Crash(*this); }
public:
	Crash();
	Crash(Transform _Info) : Object(_Info) {};
	virtual ~Crash();
};

