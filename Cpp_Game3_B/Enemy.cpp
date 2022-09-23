#include "Enemy.h"
#include "Bridge.h"
#include "Bullet.h"
#include "EnemyCar.h"
#include "EnemyTruck.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "MathManager.h"

Bridge* Enemy::BridgeList[3];

Enemy::Enemy() : pBridge(nullptr), Time(0), Reload(0)
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

	BridgeList[EnemyID_Car] = new EnemyCar;
	BridgeList[EnemyID_Truck] = new EnemyTruck;
	//BridgeList[EnemyID_Boss] = new Boss;

	Time = GetTickCount64();
	Reload = GetTickCount64();

	return this;
}

int Enemy::Update()
{
	if (pBridge)
	{
		pBridge->Update(Info);
		if (Index == 1)
		{
			if (Reload + 500 < GetTickCount64())
			{
				Object* pObj = ObjectManager::GetInstance()->GetObj("Bullet");
				//((Bullet*)pObj)->SetBridge(((Bullet*)pObj)->GetBridge(0)->Clone());
				pObj->SetIndex(1);
				pObj->SetPosition(Info.Position);
				((Bullet*)pObj)->SetShooter(this);
				pObj->SetDirection(MathManager::GetDirection(Info.Position, ObjectManager::GetInstance()->GetPlayer()->GetPosition()));
				ObjectManager::GetInstance()->PutEnable("Bullet", pObj);
				Reload = GetTickCount64();
			}
		}
		else if (Index == 2)
		{			
			if (Reload + 200 < GetTickCount64())
			{
				Object* pObj = ObjectManager::GetInstance()->GetObj("Bullet");
				//((Bullet*)pObj)->SetBridge(((Bullet*)pObj)->GetBridge(2)->Clone());
				pObj->SetIndex(1);
				pObj->SetPosition(Info.Position);
				if (Info.Position.x >= 142)
					pObj->SetPosition(Info.Position - Vector3(3.0f, 0.0f));
				else if (Info.Position.x <= 8)
					pObj->SetPosition(Info.Position + Vector3(3.0f, 0.0f));
				((Bullet*)pObj)->SetShooter(this);
				pObj->SetDirection(MathManager::GetDirection(Info.Position, ObjectManager::GetInstance()->GetPlayer()->GetPosition()));
				ObjectManager::GetInstance()->PutEnable("Bullet", pObj);
				Reload = GetTickCount64();
			}
		}
		
	}
	else
	{
		srand(int(Time * GetTickCount64()));
		switch (rand() % 3)
		{
		case 0:
		case 1:
			pBridge = BridgeList[EnemyID_Car]->Clone();
			Info.Scale = Vector3(14.0f, 2.0f);
			Index = 1;
			Weight = 1.5f;
			HP = 50;
			//break;
		case 2:
			pBridge = BridgeList[EnemyID_Truck]->Clone();
			Info.Scale = Vector3(16.0f, 3.0f);
			Index = 2;
			Weight = 2.5f;
			HP = 75;
			break;
		}
		pBridge->Start();
		pBridge->SetObject(this);
	}

	

	if (Info.Position.x - Info.Scale.x / 2 <= 1 || Info.Position.x + Info.Scale.x / 2 >= 150 || HP <= 0)
	{
		Release();
		return 1;
	}

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
