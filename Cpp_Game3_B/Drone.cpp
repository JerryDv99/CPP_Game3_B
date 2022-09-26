#include "Drone.h"
#include "Bullet.h"
#include "Enemy.h"
#include "MathManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"


Drone::Drone() : Reload(0), B(false), Duration(0)
{
}

Drone::~Drone()
{
}

Object* Drone::Start(string _Key)
{
	Key = _Key;

	Info.Position = Vector3(128.0f, 1.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(8.0f, 4.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Reload = GetTickCount64();
	B = false;
	Duration = 0;
	Index = 0;

	Texture[0] = (char*)"¡Û  ¡Û";
	Texture[1] = (char*)"  ¡á";
	Texture[2] = (char*)"¡Û  ¡Û";
	Texture[3] = (char*)"¡Ü  ¡Ü";
	Texture[4] = (char*)"  ¡á";
	Texture[5] = (char*)"¡Ü  ¡Ü";

	return this;
}

int Drone::Update()
{
	B = !B;
	Duration++;
	

	Target = ObjectManager::GetInstance()->SearchObj("Enemy");

	if (Reload + 500 < GetTickCount64() && Target)
	{
		Object* pObj = ObjectManager::GetInstance()->GetObj("Bullet");
		pObj->SetIndex(0);
		pObj->SetPosition(Info.Position);
		((Bullet*)pObj)->SetShooter(this);
		pObj->SetDirection(MathManager::GetDirection(Info.Position, Target->GetPosition()));
		ObjectManager::GetInstance()->PutEnable("Bullet", pObj);
		Reload = GetTickCount64();
	}

	if (Duration >= 1200)
	{
		Duration = 0;
		return 1;
	}
	return 0;
}

void Drone::Render()
{
	float StartPosX = Info.Position.x - Info.Scale.x / 2;
	if (B)
		for (int i = 0; i < 3; ++i)
			CursorManager::GetInstance()->WriteBuffer(StartPosX, Info.Position.y - 1 + i, Texture[i], 3);
	else 
		for (int i = 0; i < 3; ++i)
			CursorManager::GetInstance()->WriteBuffer(StartPosX, Info.Position.y - 1 + i, Texture[i + 3], 3);
}

void Drone::Release()
{
}
