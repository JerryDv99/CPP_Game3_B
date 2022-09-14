#include "Enemy.h"
#include "Bridge.h"

Bridge* Enemy::BridgeList[3];

Enemy::Enemy() : pBridge(nullptr), Time(0)
{
	for (int i = 0; i < 3; ++i)
		BridgeList[i] = nullptr;
}

Enemy::~Enemy()
{
	Release();
}

Object* Enemy::Start(string _Key)
{
	Key = _Key;

	pBridge = nullptr;

	//BridgeList[EnemyID_Car] = new EnemyCar;
	//BridgeList[EnemyID_Truck] = new EnemyTruck;
	//BridgeList[EnemyID_Boss] = new Boss;

	Time = GetTickCount64();

	return this;
}

int Enemy::Update()
{
	if (pBridge)
		pBridge->Update(Info);
	return 0;
}

void Enemy::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Enemy::Release()
{
	if (pBridge)
	{
		delete pBridge;
		pBridge = nullptr;
	}
}
