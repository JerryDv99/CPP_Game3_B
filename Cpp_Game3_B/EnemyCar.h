#pragma once
#include "EnemyBridge.h"

class EnemyCar : public EnemyBridge
{
private:
	char* Texture[4];
public:
	virtual void Start()override;
	virtual int Update(Transform& _Transform)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	virtual Bridge* Clone()override { return new EnemyCar(*this); }
public:
	EnemyCar();
	virtual ~EnemyCar();
};