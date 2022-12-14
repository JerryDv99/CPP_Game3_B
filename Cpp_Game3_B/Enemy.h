#pragma once
#include "Object.h"

class Bridge;
class Bullet;
class Enemy : public Object
{
private:
	static Bridge* BridgeList[EnemyID_MAX];

private:
	Bridge* pBridge;
	ULONGLONG Time;
	ULONGLONG Reload;
public:
	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Enemy(*this); }
public:
	Enemy();
	Enemy(Transform _Info) : Object(_Info) {};
	virtual ~Enemy();
};

