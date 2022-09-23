#pragma once
#include "Object.h"

class Bridge;
class Bullet : public Object
{
private:
	static Bridge* BridgeList[BulletID_MAX];
private:
	Bridge* pBridge;
	ULONGLONG Time;
	Object* pShooter;
public:
	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }
	void SetShooter(Object* _Object) { pShooter = _Object; }
	Bridge* GetBridge(int _ID) { return BridgeList[_ID]; }
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Bullet(*this); }
public:
	Bullet();
	Bullet(Transform _Info) : Object(_Info) {};
	virtual ~Bullet(); 
};

