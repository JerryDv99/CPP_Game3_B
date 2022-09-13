#pragma once
#include "Object.h"

class UserInterface;
class UI : public Object
{
private:
	UserInterface* Box;
public:
	virtual Object* Start(string _Key)override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new UI(*this); }
public:
	UI();
	UI(Transform _Info) : Object(_Info) {};
	virtual ~UI();
};

