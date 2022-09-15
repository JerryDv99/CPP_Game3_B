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
#include "Player.h"

Stage::Stage() : Spd(0)
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

	Object* pObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();
	Object* pBG = PrototypeManager::GetInstance()->FindObject("BackGround")->Clone();

	if (pObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(pObj);
	
	if (pBG != nullptr)
		ObjectManager::GetInstance()->SetBG(pBG);

	char* Texture[Max][4] = {
		{
			(char*)"   ¥¹   ",
			(char*)"   ¥¹   ",
			(char*)" SPIKE",
			(char*)" STRIP"
		},

		{
			(char*)" £ï_£ï",
			(char*)" £ï-£ï",
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
	Spd = ((int)((Player*)ObjectManager::GetInstance()->GetPlayer())->GetSpeed());
	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();


	switch (Spd / 10)
	{
	case 0:
	case 10:
		CursorManager::GetInstance()->WriteBuffer(123, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)"|  /|", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"| + |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"|/  |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)" ---", 11);
		break;
	case 1:
	case 11:
		CursorManager::GetInstance()->WriteBuffer(123, 37, (char*)" _", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"  +", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)" ---", 11);
		break;
	case 12:
	case 2:
		CursorManager::GetInstance()->WriteBuffer(123, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)" ---", 11);
		break;
	case 13:
	case 3:
		CursorManager::GetInstance()->WriteBuffer(123, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)" ---", 11);
		break;
	case 4:
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)"|  | ", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)" -+--", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"   |", 11);
		break;
	case 5:
		CursorManager::GetInstance()->WriteBuffer(123, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)" ---", 11);
		break;
	case 6:
		CursorManager::GetInstance()->WriteBuffer(123, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"|-+-", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)" ---", 11);
		break;
	case 7:
		CursorManager::GetInstance()->WriteBuffer(123, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)"    /", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)"   +", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"  /", 11);
		break;
	case 8:
		CursorManager::GetInstance()->WriteBuffer(123, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)" ---", 11);		
		break;
	case 9:
		CursorManager::GetInstance()->WriteBuffer(123, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 38, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 39, (char*)" -+-|", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 40, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(123, 41, (char*)" ---", 11);
		break;
	}
	switch (Spd % 10)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(129, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)"|  /|", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"| + |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"|/  |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)" ---", 11);
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(129, 37, (char*)" _", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"  +", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)" ---", 11);
		break;
	case 2:
		CursorManager::GetInstance()->WriteBuffer(129, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)" ---", 11);
		break;
	case 3:
		CursorManager::GetInstance()->WriteBuffer(129, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)" ---", 11);
		break;
	case 4:
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)"|  | ", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)" -+--", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"   |", 11);
		break;
	case 5:
		CursorManager::GetInstance()->WriteBuffer(129, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)" ---", 11);
		break;
	case 6:
		CursorManager::GetInstance()->WriteBuffer(129, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)"|", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"|-+-", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)" ---", 11);
		break;
	case 7:
		CursorManager::GetInstance()->WriteBuffer(129, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)"    /", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)"   +", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"  /", 11);
		break;
	case 8:
		CursorManager::GetInstance()->WriteBuffer(129, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)" -+-", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)" ---", 11);
		break;
	case 9:
		CursorManager::GetInstance()->WriteBuffer(129, 37, (char*)" ___", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 38, (char*)"|   |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 39, (char*)" -+-|", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 40, (char*)"    |", 11);
		CursorManager::GetInstance()->WriteBuffer(129, 41, (char*)" ---", 11);
		break;
	}

	if (Spd >= 100)
	{
		CursorManager::GetInstance()->WriteBuffer(117, 37, (char*)" _", 11);
		CursorManager::GetInstance()->WriteBuffer(117, 38, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(117, 39, (char*)"  +", 11);
		CursorManager::GetInstance()->WriteBuffer(117, 40, (char*)"  |", 11);
		CursorManager::GetInstance()->WriteBuffer(117, 41, (char*)" ---", 11);
	}

	for (vector<Object*>::iterator iter = pSkillList.begin(); iter != pSkillList.end(); ++iter)
		(*iter)->Render();
	CursorManager::GetInstance()->WriteBuffer(135, 38, (char*)"| / ._ _ ", 11);
	CursorManager::GetInstance()->WriteBuffer(135, 39, (char*)"|¡¬ | | | /", 11);
	CursorManager::GetInstance()->WriteBuffer(143, 40, (char*)" / |_", 11);
	CursorManager::GetInstance()->WriteBuffer(146, 41, (char*)"| |", 11);


	CursorManager::GetInstance()->WriteBuffer(120, 32, (char*)"½º", 14);
	CursorManager::GetInstance()->WriteBuffer(120, 35, (char*)"Å³", 14);

}

void Stage::Release()
{
}
