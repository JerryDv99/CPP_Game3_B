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

	Texture[0] = "   __*_";
	Texture[1] = "¦£\"LSPD`¦¡¦¤";
	Texture[2] = "¦¦£ï¦¡¦¡£ï¦¥";

	Texture[3] = "¦£¦¡¦¡¦¡¦¡**¦¤";
	Texture[4] = "¦¢       ¦¢ ¦¢___";
	Texture[5] = "¦¢ LSPD         ¦¢";
	Texture[6] = "¦¦¦¡£ï¦¡¦¡¦¡¦¡£ï¦¥";

	return nullptr;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (!Temp)
		T++;
	if (Temp)
		T--;
	if (T == 0 && Temp)
		Temp = false;
	if (T == 20 && !Temp)
		Temp = true;

	if (dwKey & KEY_UP)
		Info.Position.y--;

	if (dwKey & KEY_DOWN)
		Info.Position.y++;

	if (dwKey & KEY_LEFT)
		Info.Position.x -= 2;

	if (dwKey & KEY_RIGHT)
		Info.Position.x += 2;

	return 0;
}

void Player::Render()
{
	if (!Index)
	{
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 2, Texture[0]);
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 1, Texture[1]);
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, Texture[2]);
		if (Temp)
			CursorManager::GetInstance()->WriteBuffer(Info.Position.x + 5, Info.Position.y - 2, "*", 12);
		if(!Temp)
			CursorManager::GetInstance()->WriteBuffer(Info.Position.x + 5, Info.Position.y - 2, "*", 9);
	}
	if (Index)
	{
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 3, Texture[3]);
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 2, Texture[4]);
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y - 1, Texture[5]);
		CursorManager::GetInstance()->WriteBuffer(Info.Position.x, Info.Position.y, Texture[6]);
		if (Temp)
			CursorManager::GetInstance()->WriteBuffer(Info.Position.x + 10, Info.Position.y - 2, "**", 12);
		if (!Temp)
			CursorManager::GetInstance()->WriteBuffer(Info.Position.x + 10, Info.Position.y - 2, "**", 9);
	}
}

void Player::Release()
{
}
