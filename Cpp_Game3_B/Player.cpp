#include "Player.h"
#include "CursorManager.h"
#include "InputManager.h"

Player::Player() : Index(0), Temp(false)
{
	for (int i = 0; i < 8; ++i)
		Texture[i] = "";
}

Player::~Player()
{
	Release();
}

Object* Player::Start(string _Key)
{
	Key = _Key;

	Info.Position = Vector3(10.0f, 20.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(12.0f, 2.0f);

	Target = nullptr;

	Speed = 70.0f;

	Index = 1;

	Texture[0] = "   __*_";
	Texture[1] = "��\"LSPD`����";
	Texture[2] = "���說���殮";

	Texture[3] = "����������**��";
	Texture[4] = "��       �� ��___";
	Texture[5] = "�� LSPD         ��";
	Texture[6] = "�����說�������殮";

	return this;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	Vector3 StartPoint = Info.Position - Info.Scale / 2;
	Vector3 EndPoint = Info.Position + Info.Scale / 2;

	if (Index)
		 EndPoint = Info.Position + Info.Scale / 2 - Vector3(0.0f, 1.0f);

	if (!Temp)
		T++;
	if (Temp)
		T--;
	if (T == 0 && Temp)
		Temp = false;
	if (T == 20 && !Temp)
		Temp = true;

	if (dwKey & KEY_UP)
	{
		if (Info.Position.y > 6)
			Info.Position.y -= 7;
	}

	if (dwKey & KEY_DOWN)
	{
		if (Info.Position.y < 27)
		Info.Position.y += 7;
	}

	if (dwKey & KEY_LEFT)
	{
		if (Speed > 20)
			Speed --;
		if (StartPoint.x > 0)
			Info.Position.x -= 1 * (Speed * 0.01f);
	}


	if (dwKey & KEY_RIGHT)
	{
		if (Speed < 120)
			Speed++;
		if(EndPoint.x < 100 + Speed / 3)
			Info.Position.x += 1.5f * (Speed * 0.01f);
	}

	return 0;
}

void Player::Render()
{
	Vector3 StartPoint = Info.Position - Info.Scale / 2;

	if (!Index)
	{
		CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y - 1, Texture[0]);
		CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y, Texture[1]);
		CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y + 1, Texture[2]);
		if (Temp)
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x + 5, Info.Position.y - 1, "*", 12);
		if(!Temp)
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x + 5, Info.Position.y - 1, "*", 9);
	}
	if (Index)
	{
		CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y - 2, Texture[3]);
		CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y - 1, Texture[4]);
		CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y, Texture[5]);
		CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y + 1, Texture[6]);
		if (Temp)
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x + 10, Info.Position.y - 2, "**", 12);
		if (!Temp)
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x + 10, Info.Position.y - 2, "**", 9);
	}
	CursorManager::GetInstance()->WriteBuffer(140, 44, Speed, 11);
}

void Player::Release()
{
}
