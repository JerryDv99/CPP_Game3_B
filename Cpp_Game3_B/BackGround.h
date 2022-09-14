#pragma once
#include "Object.h"

class BackGround : public Object
{
private:
	char* Texture[16];
	float Count;
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new BackGround(*this); }
public:
	BackGround();
	BackGround(Transform _Info) : Object(_Info) {};
	virtual ~BackGround();
};

