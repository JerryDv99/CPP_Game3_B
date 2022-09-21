#pragma once
#include "EnemyBridge.h"

class EnemyTruck : public EnemyBridge
{
private:
	char* Texture[4];
public:
	virtual void Start()override;
	virtual int Update(Transform& _Transform)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	virtual Bridge* Clone()override { return new EnemyTruck(*this); }
public:
	EnemyTruck();
	virtual ~EnemyTruck();
};

