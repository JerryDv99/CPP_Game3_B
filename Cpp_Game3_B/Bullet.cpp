#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

Object* Bullet::Start(string _Key)
{
	Key = _Key;

	Speed = 1.0f;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Info.Direction = Vector3(1.0f, 0.0f);

	return this;
}

int Bullet::Update()
{
	Info.Position += Info.Direction * (Speed * 1.5f);

	if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 30)
		return 1;

	return 0;
}

void Bullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 14);
}

void Bullet::Release()
{
}