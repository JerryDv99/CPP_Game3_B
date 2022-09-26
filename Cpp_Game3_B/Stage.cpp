#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "PrototypeManager.h"
#include "ObjectManager.h"
#include "ObjectpoolManager.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "BackGround.h"
#include "ScrollBox.h"
#include "Skill.h"
#include "Drone.h"
#include "Player.h"
#include "SpikeStrip.h"

Stage::Stage() : Spd(0), Score(0), SkillGauge1(0), SkillGauge2(0), Progress(0)
{
	for (int i = 0; i < 8; ++i)
		Texture[i] = (char*)"";
}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	Spd = 0;
	Score = 0;
	SkillGauge1 = 0;
	SkillGauge2 = 0;
	Progress = 0;
	Respawn = GetTickCount64();

	Object* pObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();
	Object* pBG = PrototypeManager::GetInstance()->FindObject("BackGround")->Clone();

	if (pObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(pObj);
	
	if (pBG != nullptr)
		ObjectManager::GetInstance()->SetBG(pBG);

	char* Texture[Max][4] = {
		{
			(char*)"   Ⅹ   ",
			(char*)"   Ⅹ   ",
			(char*)" SPIKE",
			(char*)" STRIP"
		},

		{
			(char*)" ｏ_ｏ",
			(char*)" ｏ-ｏ",
			(char*)" DRONE ",
			(char*)"SUPPORT",
		}
	};

	for (int i = 0; i < Max; ++i)
	{
		Object* pSkill = new Skill;
		pSkill->SetPosition(
			int(12 * i + (150 - (10 * Max))),
			int(37 - (7 * 0.5f)));

		pSkill->Start("Skill");

		((Skill*)pSkill)->SetTexture(Texture[i]);

		pSkillList.push_back(pSkill);
	}
}

void Stage::Update()
{
	vector<Object*>::iterator iter = pSkillList.begin();
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	Spd = ((int)((Player*)ObjectManager::GetInstance()->GetPlayer())->GetSpeed());

	for (vector<Object*>::iterator iter = pSkillList.begin(); iter != pSkillList.end(); ++iter)
		(*iter)->Update();

	SkillGauge1 += 5;
	SkillGauge2 ++;

	if (SkillGauge1 >= 100)
		(*iter)->SetIndex(1);
	if (SkillGauge1 >= 200)
		(*iter)->SetIndex(2);
	if (SkillGauge1 >= 300)
		(*iter)->SetIndex(3);
	if (SkillGauge1 >= 400)
		(*iter)->SetIndex(4);
	if (SkillGauge1 >= 500)
		(*iter)->SetIndex(5);
	
	if (SkillGauge2 >= 200)
		(*(iter + 1))->SetIndex(1);
	if (SkillGauge2 >= 400)
		(*(iter + 1))->SetIndex(2);
	if (SkillGauge2 >= 600)
		(*(iter + 1))->SetIndex(3);
	if (SkillGauge2 >= 800)
		(*(iter + 1))->SetIndex(4);
	if (SkillGauge2 >= 1000)
		(*(iter + 1))->SetIndex(5);

	if (Respawn + 7000 < GetTickCount64())
	{
		srand(GetTickCount64() * Respawn);
		Respawn = GetTickCount64();
		switch (rand() % 4)
		{
		case 0:
			if (Spd < 110)
				ObjectManager::GetInstance()->AddObject("Enemy", Vector3(132.0f, 6.0f));
			else
				ObjectManager::GetInstance()->AddObject("Enemy", Vector3(20.0f, 6.0f));
			break;
		case 1:
			if (Spd < 110)
				ObjectManager::GetInstance()->AddObject("Enemy", Vector3(132.0f, 13.0f));
			else
				ObjectManager::GetInstance()->AddObject("Enemy", Vector3(20.0f, 13.0f));
			break;
		case 2:
			if (Spd < 110)
				ObjectManager::GetInstance()->AddObject("Enemy", Vector3(132.0f, 20.0f));
			else
				ObjectManager::GetInstance()->AddObject("Enemy", Vector3(20.0f, 20.0f));
			break;
		case 3:
			if (Spd < 110)
				ObjectManager::GetInstance()->AddObject("Enemy", Vector3(132.0f, 27.0f));
			else
				ObjectManager::GetInstance()->AddObject("Enemy", Vector3(20.0f, 27.0f));
			break;
		}		
	}

	if (SkillGauge1 >= 500 && dwKey & KEY_R)
	{
		SkillGauge1 = 0;
		(*iter)->SetIndex(0);
		((Player*)ObjectManager::GetInstance()->GetPlayer())->SetSpike(true);
		switch ((int)ObjectManager::GetInstance()->GetPlayer()->GetPosition().y)
		{
		case 6:
			ObjectManager::GetInstance()->AddObject("SpikeStrip", Vector3(148, 13));
			ObjectManager::GetInstance()->AddObject("SpikeStrip", Vector3(148, 27));
			break;
		case 13:
			ObjectManager::GetInstance()->AddObject("SpikeStrip", Vector3(148, 6));
			ObjectManager::GetInstance()->AddObject("SpikeStrip", Vector3(148, 20));
			break;
		case 20:
			ObjectManager::GetInstance()->AddObject("SpikeStrip", Vector3(148, 13));
			ObjectManager::GetInstance()->AddObject("SpikeStrip", Vector3(148, 27));
			break;
		case 27:
			ObjectManager::GetInstance()->AddObject("SpikeStrip", Vector3(148, 6));
			ObjectManager::GetInstance()->AddObject("SpikeStrip", Vector3(148, 20));
			break;
		}
		
	}
	if (Progress < 200)
		Progress++;
	if (SkillGauge2 >= 1000 && dwKey & KEY_T)
	{
		SkillGauge2 = 0;
		(*(iter + 1))->SetIndex(0);
		ObjectManager::GetInstance()->AddObject("Drone", Vector3(142, 4));
	}

	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();


	switch (Spd / 10)
	{
	case 0:
	case 10:
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"|  /|", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"| + |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)"|/  |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 42, (char*)" ---", 11);
		break;
	case 1:
	case 11:
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)" _", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"  +", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 42, (char*)" ---", 11);
		break;
	case 2:
	case 12:
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 42, (char*)" ---", 11);
		break;
	case 3:
	case 13:
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 42, (char*)" ---", 11);
		break;
	case 4:
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"|  | ", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)" -+--", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)"   |", 11);
		break;
	case 5:
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 42, (char*)" ---", 11);
		break;
	case 6:
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"|-+-", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 42, (char*)" ---", 11);
		break;
	case 7:
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"    /", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"   +", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)"  /", 11);
		break;
	case 8:
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 42, (char*)" ---", 11);
		break;
	case 9:
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)" -+-|", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 42, (char*)" ---", 11);
		break;
	}
	switch (Spd % 10)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"|  /|", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"| + |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)"|/  |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 42, (char*)" ---", 11);
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)" _", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"  +", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 42, (char*)" ---", 11);
		break;
	case 2:
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 42, (char*)" ---", 11);
		break;
	case 3:
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 42, (char*)" ---", 11);
		break;
	case 4:
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"|  | ", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)" -+--", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)"   |", 11);
		break;
	case 5:
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 42, (char*)" ---", 11);
		break;
	case 6:
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"|-+-", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 42, (char*)" ---", 11);
		break;
	case 7:
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"    /", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"   +", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)"  /", 11);
		break;																	   
	case 8:
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 42, (char*)" ---", 11);
		break;
	case 9:
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)" -+-|", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 42, (char*)" ---", 11);
		break;
	}

	if (Spd >= 100)
	{
		CursorManager::GetInstance()->WriteBuffer(117, 38, (char*)" _", 11);
		CursorManager::GetInstance()->WriteBuffer(117, 39, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(117, 40, (char*)"  +", 11);
		CursorManager::GetInstance()->WriteBuffer(117, 41, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(117, 42, (char*)" ---", 11);
	}

	for (vector<Object*>::iterator iter = pSkillList.begin(); iter != pSkillList.end(); ++iter)
		(*iter)->Render();

	CursorManager::GetInstance()->WriteBuffer(135, 39, (char*)"| / ._ _ ", 11);
	CursorManager::GetInstance()->WriteBuffer(135, 40, (char*)"|＼ | | | /", 11);
	CursorManager::GetInstance()->WriteBuffer(143, 41, (char*)" / |_", 11);
	CursorManager::GetInstance()->WriteBuffer(146, 42, (char*)"| |", 11);


	CursorManager::GetInstance()->WriteBuffer(120, 32, (char*)"스", 14);
	CursorManager::GetInstance()->WriteBuffer(120, 35, (char*)"킬", 14);


	if(SkillGauge1 >= 500)
		CursorManager::GetInstance()->WriteBuffer(131, 37, (char*)"R", 10);
	else
		CursorManager::GetInstance()->WriteBuffer(131, 37, (char*)"R", 8);

	if(SkillGauge2 >= 1000)
		CursorManager::GetInstance()->WriteBuffer(142, 37, (char*)"T", 10);
	else
		CursorManager::GetInstance()->WriteBuffer(142, 37, (char*)"T", 8);

	CursorManager::GetInstance()->WriteBuffer(42, 0, (char*)"스테이지", 11);
	CursorManager::GetInstance()->WriteBuffer(43, 1, (char*)"진행도", 11);

	CursorManager::GetInstance()->WriteBuffer(75 - strlen("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓") / 2, 0, (char*)"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	CursorManager::GetInstance()->WriteBuffer(75 - strlen("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓") / 2, 1, (char*)"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");

	int Pro = Progress / 10;
	CursorManager::GetInstance()->WriteBuffer(53 + Pro * 2, 0, (char*)"플레", 9);
	CursorManager::GetInstance()->WriteBuffer(53 + Pro * 2, 1, (char*)"이어", 12);
		

}

void Stage::Release()
{
}
