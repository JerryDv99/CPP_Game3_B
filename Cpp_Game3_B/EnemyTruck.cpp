#include "EnemyTruck.h"
#include "Enemy.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "Player.h"

EnemyTruck::EnemyTruck()
{
	for (int i = 0; i < 4; ++i)
		Texture[i] = (char*)"";
}

EnemyTruck::~EnemyTruck()
{
}

void EnemyTruck::Start()
{
	int Spd = ((Player*)ObjectManager::GetInstance()->GetPlayer())->GetSpeed();

	Texture[0] = (char*)"        ____";
	Texture[1] = (char*)"式成 褡太  ]′_";
	Texture[2] = (char*)"忙扛-扛戎     弛";
	Texture[3] = (char*)"戌式≡式式式≡戎";
}

int EnemyTruck::Update(Transform& _Transform)
{
	int Spd = ((Player*)ObjectManager::GetInstance()->GetPlayer())->GetSpeed();

	if (Spd <= 50 && pObject->GetEndPos() < 146)
		_Transform.Position.x += 0.5f;

	if (Spd >= 100)
		_Transform.Position.x -= 0.5f;

	return 0;
}

void EnemyTruck::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetStartPos(), pObject->GetPosition().y - 2, Texture[0], 12);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetStartPos(), pObject->GetPosition().y - 1, Texture[1], 12);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetStartPos(), pObject->GetPosition().y, Texture[2], 12);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetStartPos(), pObject->GetPosition().y + 1, Texture[3], 12);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetStartPos() + 5, pObject->GetPosition().y - 1, (char*)"褡", 4);
}

void EnemyTruck::Release()
{
}
