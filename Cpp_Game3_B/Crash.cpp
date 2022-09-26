#include "Crash.h"
#include "CursorManager.h"

Crash::Crash() : Count(0)
{
}

Crash::~Crash()
{
}

Object* Crash::Start(string _Key)
{
	Key = _Key;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(10.0f, 5.0f);
	Info.Direction = Vector3(1.0f, 0.0f);

	Count = 0;

	Texture[0] = (char*)"『  『  『";
	Texture[1] = (char*)" 『『『『";
	Texture[2] = (char*)"『!BOOM!『";
	Texture[3] = (char*)" 『『『『";
	Texture[4] = (char*)"『  『  『";

	return this;
}

int Crash::Update()
{
	Count++;
	if (Count >= 30)
	{
		Count = 0;
		return 1;
	}
	return 0;
}

void Crash::Render()
{
	for (int i = 0; i < 5; ++i)
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 2 + i, Texture[i], 12);
}

void Crash::Release()
{
}
