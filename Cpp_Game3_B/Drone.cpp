#include "Drone.h"
#include "ObjectManager.h"


Drone::Drone()
{
}

Drone::~Drone()
{
	Release();
}

Object* Drone::Start(string _Key)
{
	Key = _Key;

	Info.Position = Vector3(138.0f, 3.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(8.0f, 4.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	return this;
}

int Drone::Update()
{
	return 0;
}

void Drone::Render()
{
}

void Drone::Release()
{
}
