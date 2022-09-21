#pragma once
#include "Object.h"

class Drone : public Object
{
private:
	ULONGLONG Reload;
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Drone(*this); }
public:
	Drone();
	Drone(Transform _Info) : Object(_Info) {};
	virtual ~Drone();
};