#include "EnemyCar.h"
#include "Enemy.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "Player.h"

EnemyCar::EnemyCar()
{
	for (int i = 0; i < 4; ++i)
		Texture[i] = (char*)"";
}

EnemyCar::~EnemyCar()
{
}

void EnemyCar::Start()
{
	int Spd = ((Player*)ObjectManager::GetInstance()->GetPlayer())->GetSpeed();

	Texture[0] = (char*)"    _____";
	Texture[1] = (char*)"¦£-¢©    `¦¡¦¤";
	Texture[2] = (char*)"¦¦-£ï¦¡¦¡-£ï¦¥";
	Texture[3] = (char*)"¿À";
}

int EnemyCar::Update(Transform& _Transform)
{
	int Spd = ((Player*)ObjectManager::GetInstance()->GetPlayer())->GetSpeed();

	if (Spd <= 60 && pObject->GetEndPos() < 146)
		_Transform.Position.x += 0.5f;

	if (Spd >= 110)
		_Transform.Position.x -= 0.5f;

	return 0;
}

void EnemyCar::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetStartPos(), pObject->GetPosition().y - 1, Texture[0], 12);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetStartPos(), pObject->GetPosition().y, Texture[1], 12);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetStartPos(), pObject->GetPosition().y + 1, Texture[2], 12);
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetStartPos() + 7, pObject->GetPosition().y, Texture[3], 4);
}

void EnemyCar::Release()
{
}
