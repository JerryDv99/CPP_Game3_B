#include "SpikeStrip.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "Player.h"

SpikeStrip::SpikeStrip()
{
}

SpikeStrip::~SpikeStrip()
{
	Release();
}

Object* SpikeStrip::Start(string _Key)
{
	Key = _Key;
	
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	return this;
}

int SpikeStrip::Update()
{
	int Speed = ((Player*)ObjectManager::GetInstance()->GetPlayer())->GetSpeed();

	Info.Position.x -= 3 * (Speed * 0.01);

	if (Info.Position.x <= 0)
		return 1;

	return 0;
}

void SpikeStrip::Render()
{
	for (int i = 0; i < 6; ++i)
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 3 + i, (char*)"X", 3);

	CursorManager::GetInstance()->WriteBuffer(Info.Position.x + 3, Info.Position.y + 3, Info.Position.x, 10);
	CursorManager::GetInstance()->WriteBuffer(Info.Position.x + 3, Info.Position.y + 4, Info.Position.y, 10);
}

void SpikeStrip::Release()
{
}
