#pragma once
#include "Object.h"

class SpikeStrip : public Object
{
private:

public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new SpikeStrip(*this); }
public:
	SpikeStrip();
	SpikeStrip(Transform _Info) : Object(_Info) {};
	virtual ~SpikeStrip();
};