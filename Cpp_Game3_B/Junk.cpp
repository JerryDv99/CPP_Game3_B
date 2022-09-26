#include "Junk.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "Player.h"

Junk::Junk()
{
}

Junk::~Junk()
{
}

Object* Junk::Start(string _Key)
{
	Key = _Key;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 3.0f);
	Info.Direction = Vector3(1.0f, 0.0f);

	Weight = 1.0f;

	Texture[0] = (char*)"けいしぉ";
	Texture[1] = (char*)"つびちぱ";
	Texture[2] = (char*)"しぱした";

	return this;
}

int Junk::Update()
{
	Info.Position.x -= 0.03f * ObjectManager::GetInstance()->GetPlayer()->GetSpeed();

	if (Info.Position.x <= 3.3)
		return 1;
	return 0;
}

void Junk::Render()
{
	for (int i = 0; i < 3; ++i)
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 1 + i, Texture[i], 6);
}

void Junk::Release()
{
}