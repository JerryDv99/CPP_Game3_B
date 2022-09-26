#include "Item.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Player.h"

Item::Item()
{
}

Item::~Item()
{
}

Object* Item::Start(string _Key)
{
	Key = _Key;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 3.0f);
	Info.Direction = Vector3(1.0f, 0.0f);

	Texture[0] = (char*)"BulletProof";
	Texture[1] = (char*)" Upgrade";
	Texture[2] = (char*)"Burst";
	Texture[3] = (char*)"Ammo";
	Texture[4] = (char*)"Repair";
	Texture[5] = (char*)"ToolKit";

	return this;
}

int Item::Update()
{
	Info.Position.x--;
	srand(GetTickCount64() * (GetTickCount64() / 123));
	if (!Index)
	{
		switch (rand() % 3)
		{
		case 0:
			Index = 1;
			break;
		case 1:
			Index = 2;
			break;
		case 2:
			Index = 3;
			break;
		}
	}	

	if (Info.Position.x <= 1)
	{
		Index = 0;
		return 1;
	}
	if (ObjectManager::GetInstance()->Collision("Player", this))
	{
		((Player*)ObjectManager::GetInstance()->GetPlayer())->SetBuff(Index);
		Index = 0;
		return 1;
	}
	return 0;
}

void Item::Render()
{
	if(Index == 1)
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 1 + i, Texture[i], 9);
	if(Index == 2)
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 1 + i, Texture[i + 2], 12);
	if(Index == 3)
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 1 + i, Texture[i + 4], 10);
}

void Item::Release()
{
}
