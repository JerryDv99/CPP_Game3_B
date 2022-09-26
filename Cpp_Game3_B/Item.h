#pragma once
#include "Object.h"

class Item : public Object
{
private:
	char* Texture[8];
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Item(*this); }
public:
	Item();
	Item(Transform _Info) : Object(_Info) {};
	virtual ~Item();
};

