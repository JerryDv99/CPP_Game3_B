#include "Player.h"
#include "Bullet.h"
#include "Bridge.h"
#include "CursorManager.h"
#include "CollisionManager.h"
#include "ObjectManager.h"
#include "InputManager.h"

Player::Player() : Temp(false), Spike(false), BuffTime(0), Buff(0), Armor(false), PowerUp(false)
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

	Index = 1;
	HP = 200;
	if (Index)
		HP = 400;
	Speed = 70.0f;
	Weight = 1.9f;
	Delay = GetTickCount64();
	Reload = GetTickCount64();
	BuffTime = GetTickCount64();
	Buff = 0;
	Armor = 0;
	Spike = false;
	PowerUp = false;
	
	Texture[0] = "   __*_";
	Texture[1] = "忙\"LSPD`式忖";
	Texture[2] = "戌�鵀’﹝鵀�";

	Texture[3] = "忙式式式式**忖";
	Texture[4] = "弛       弛 弛___";
	Texture[5] = "弛 LSPD         弛";
	Texture[6] = "戌式≡式式式式≡戎";

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

	if (dwKey & KEY_SPACE)
	{
		if (!Index && Reload + 300 < GetTickCount64())
		{
			Reload = GetTickCount64();
			Object* pObj = ObjectManager::GetInstance()->GetObj("Bullet");
			pObj->SetIndex(0);
			pObj->SetPosition(Info.Position);
			pObj->SetDirection(1.0f, 0.0f);
			((Bullet*)pObj)->SetShooter(this);
			if (dwKey & KEY_AUP)
				pObj->SetDirection(0.0f, -1.0f);
			if (dwKey & KEY_ADOWN)
				pObj->SetDirection(0.0f, 1.0f);
			if (dwKey & KEY_ALEFT)
				pObj->SetDirection(-1.0f, 0.0f);
			if (dwKey & KEY_AUP && dwKey & KEY_ALEFT)
				pObj->SetDirection(-1.0f, -0.25f);
			if (dwKey & KEY_AUP && dwKey & KEY_ARIGHT)
				pObj->SetDirection(1.0f, -0.25f);
			if (dwKey & KEY_ADOWN && dwKey & KEY_ARIGHT)
				pObj->SetDirection(1.0f, 0.25f);
			if (dwKey & KEY_ADOWN && dwKey & KEY_ALEFT)
				pObj->SetDirection(-1.0f, 0.25f);
			ObjectManager::GetInstance()->PutEnable("Bullet", pObj);
		}

		else if (Index && Reload + 2000 < GetTickCount64())
		{
			Reload = GetTickCount64();
			Object* pObj = ObjectManager::GetInstance()->GetObj("Bullet");
			Object* pObj2 = ObjectManager::GetInstance()->GetObj("Bullet");
			Object* pObj3 = ObjectManager::GetInstance()->GetObj("Bullet");
			pObj->SetIndex(0);
			pObj2->SetIndex(0);
			pObj3->SetIndex(0);
			pObj->SetPosition(Info.Position);
			pObj2->SetPosition(Info.Position);
			pObj3->SetPosition(Info.Position);
			pObj->SetDirection(1.0f, 0.0f);
			pObj2->SetDirection(1.0f, -0.1f);
			pObj3->SetDirection(1.0f, 0.1f);
			((Bullet*)pObj)->SetShooter(this);
			((Bullet*)pObj2)->SetShooter(this);
			((Bullet*)pObj3)->SetShooter(this);
			if (dwKey & KEY_AUP)
			{
				pObj->SetDirection(0.0f, -1.0f);
				pObj2->SetDirection(-0.1f, -1.0f);
				pObj3->SetDirection(0.1f, -1.0f);
			}
			if (dwKey & KEY_ADOWN)
			{
				pObj->SetDirection(0.0f, 1.0f);
				pObj2->SetDirection(-0.1f, 1.0f);
				pObj3->SetDirection(0.1f, 1.0f);
			}
			if (dwKey & KEY_ALEFT)
			{
				pObj->SetDirection(-1.0f, 0.0f);
				pObj2->SetDirection(-1.0f, -0.1f);
				pObj3->SetDirection(-1.0f, 0.1f);
			}
			if (dwKey & KEY_AUP && dwKey & KEY_ALEFT)
			{
				pObj->SetDirection(-1.0f, -0.25f);
				pObj2->SetDirection(-1.0f, -0.35f);
				pObj3->SetDirection(-1.0f, -0.15f);
			}
			if (dwKey & KEY_AUP && dwKey & KEY_ARIGHT)
			{
				pObj->SetDirection(1.0f, -0.25f);
				pObj2->SetDirection(1.0f, -0.35f);
				pObj3->SetDirection(1.0f, -0.15f);
			}
			if (dwKey & KEY_ADOWN && dwKey & KEY_ARIGHT)
			{
				pObj->SetDirection(1.0f, 0.25f);
				pObj2->SetDirection(1.0f, 0.35f);
				pObj3->SetDirection(1.0f, 0.15f);
			}
			if (dwKey & KEY_ADOWN && dwKey & KEY_ALEFT)
			{
				pObj->SetDirection(-1.0f, 0.25f);
				pObj2->SetDirection(-1.0f, 0.35f);
				pObj3->SetDirection(-1.0f, 0.15f);
			}
			ObjectManager::GetInstance()->PutEnable("Bullet", pObj);
			ObjectManager::GetInstance()->PutEnable("Bullet", pObj2);
			ObjectManager::GetInstance()->PutEnable("Bullet", pObj3);
		}
	}

	if (dwKey & KEY_UP && Delay + 100 < GetTickCount64() && !Index)
	{
		Delay = GetTickCount64();
		if (Info.Position.y > 6)
			Info.Position.y -= 7;
	}
	else if (dwKey & KEY_UP && Delay + 200 < GetTickCount64() && Index)
	{
		Delay = GetTickCount64();
		if (Info.Position.y > 6)
			Info.Position.y -= 7;
	}
	if (dwKey & KEY_DOWN && Delay + 100 < GetTickCount64() && !Index)
	{
		Delay = GetTickCount64();
		if (Info.Position.y < 27)
		Info.Position.y += 7;
	}
	else if (dwKey & KEY_DOWN && Delay + 200 < GetTickCount64() && Index)
	{
		Delay = GetTickCount64();
		if (Info.Position.y < 27)
			Info.Position.y += 7;
	}
	if (dwKey & KEY_LEFT)
	{
		if (Index)
		{
			if (Speed > 30)
				Speed--;
		}
		else
		{
			if (Speed > 40)
				Speed--;
		}
		
		if (StartPoint.x > 0)
		{
			if(Speed > 60)
				Info.Position.x -= 1.1f * (Speed * 0.01f);
			else
				Info.Position.x -= 1.0f * (Speed * 0.01f);
		}
	}

	if (Buff)
	{
		switch (Buff)
		{
		case 1:
			Armor += 100;
			Buff = 0;
			break;
		case 2:
			PowerUp = true;
			Buff = 0;
			break;
		case 3:
			HP += 50;
			Buff = 0;
			break;
		}
	}

	if (HP > 200 && !Index)
		HP = 200;
	if (HP > 400 && Index)
		HP = 400;

	if (PowerUp && BuffTime + 15000 < GetTickCount64())
		PowerUp = false;

	if (dwKey & KEY_RIGHT)
	{
		if (Index)
		{
			if (Speed < 80)
				Speed++;
		}
		else
		{
			if (Speed < 130)
				Speed++;
		}

		if (Speed > 60)
		{
			if (EndPoint.x < 70 + Speed / 2)
				Info.Position.x += 1.25f * (Speed * 0.01f);
		}		
	}

	if (ObjectManager::GetInstance()->Collision("Player", "SpikeStrip") && Spike)
	{
		Spike = false;
		HP -= 50;
	}

	if (ObjectManager::GetInstance()->Collision("Player", "Item"))
		BuffTime = GetTickCount64();

	return 0;
}

void Player::Render()
{
	Vector3 StartPoint = Info.Position - Info.Scale / 2;

	if (!Index)
	{
		if (!Armor)
		{
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y - 1, Texture[0]);
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y, Texture[1]);
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y + 1, Texture[2]);
		}
		else
		{
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y - 1, Texture[0], 3);
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y, Texture[1], 3);
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y + 1, Texture[2], 3);
		}
		if (Temp)
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x + 5, Info.Position.y - 1, "*", 12);
		if(!Temp)
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x + 5, Info.Position.y - 1, "*", 9);
	}
	if (Index)
	{
		if (!Armor)
		{
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y - 2, Texture[3]);
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y - 1, Texture[4]);
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y, Texture[5]);
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y + 1, Texture[6]);
		}
		
		else if (Armor)
		{
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y - 2, Texture[3], 3);
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y - 1, Texture[4], 3);
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y, Texture[5], 3);
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x, Info.Position.y + 1, Texture[6], 3);
		}
		if (Temp)
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x + 10, Info.Position.y - 2, "**", 12);
		if (!Temp)
			CursorManager::GetInstance()->WriteBuffer(StartPoint.x + 10, Info.Position.y - 2, "**", 9);		
	}
}

void Player::Release()
{
}
