#include "Bullet.h"
#include "Pistol.h"
#include "SG.h"
#include "MG.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectManager.h"
#include "Player.h"

Bridge* Bullet::BridgeList[BulletID_MAX];

Bullet::Bullet() : pBridge(nullptr), Time(0)
{
	for (int i = 0; i < 4; ++i)
		BridgeList[i] = nullptr;
}

Bullet::~Bullet()
{
	Release();
}

Object* Bullet::Start(string _Key)
{
	Key = _Key;

	Speed = 1.0f;

	pBridge = nullptr;

	Time = GetTickCount64();

	BridgeList[BulletID_Pistol] = new Pistol;
	BridgeList[BulletID_SG] = new SG;
	//BridgeList[BulletID_MG] = new MG;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Info.Direction = Vector3(1.0f, 0.0f);

	return this;
}

int Bullet::Update()
{
	if (pBridge)
	{
		int Result = pBridge->Update(Info);
		if (Result)
		{
			return 1;
		}
	}
	else
	{
		if (Time + 100 < GetTickCount64() && !Index)
		{
			if (!ObjectManager::GetInstance()->GetPlayer()->GetIndex())
				pBridge = BridgeList[BulletID_Pistol]->Clone();			
			else
				pBridge = BridgeList[BulletID_SG]->Clone();
		}
		else if (Time + 100 < GetTickCount64() && Index)
		{
			//if ()
		}
		pBridge->Start();
		pBridge->SetObject(this);
	}
	
	if (Info.Position.x <= 0.5 || Info.Position.x >= 148.5 ||
		Info.Position.y <= 2 || Info.Position.y >= 30)
	{
		return 1;
	}

	return 0;
}

void Bullet::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Bullet::Release()
{
	delete pBridge;
	pBridge = nullptr;
}