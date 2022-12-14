#pragma once
#include "Object.h"

class Junk : public Object
{
private:
	char* Texture[4];
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Junk(*this); }
public:
	Junk();
	Junk(Transform _Info) : Object(_Info) {};
	virtual ~Junk();
};

