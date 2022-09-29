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

Stage::Stage() : Spd(0), Score(0), SkillGauge1(0), SkillGauge2(0), Progress(0), PHP(0)
{
	for (int i = 0; i < 8; ++i)
		Texture[i] = (char*)"";
	for (int i = 0; i < 16; ++i)
		SBox[i] = (char*)"";
	for (int i = 0; i < 8; ++i)
		StatusTexture[i] = (char*)"";
	for (int i = 0; i < 8; ++i)
		StatusTexture2[i] = (char*)"";
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
	PHP = 0;
	Respawn = GetTickCount64();

	Object* pObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();
	Object* pBG = PrototypeManager::GetInstance()->FindObject("BackGround")->Clone();

	if (pObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(pObj);
	
	if (pBG != nullptr)
		ObjectManager::GetInstance()->SetBG(pBG);

	SBox[0] = (char*)"┌───────────────────────────────────┐";
	SBox[1] = (char*)"│                                                                      │";
	SBox[2] = (char*)"│                                                                      │";
	SBox[3] = (char*)"│                                                                      │";
	SBox[4] = (char*)"│                                                                      │";
	SBox[5] = (char*)"│                                                                      │";
	SBox[6] = (char*)"│                                                                      │";
	SBox[7] = (char*)"│                                                                      │";
	SBox[8] = (char*)"│                                                                      │";
	SBox[9] = (char*)"│                                                                      │";
	SBox[10] = (char*)"│                                                                      │";
	SBox[11] = (char*)"│                                                                      │";
	SBox[12] = (char*)"└───────────────────────────────────┘";


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

	StatusTexture[0] = (char*)"                        :}L}!";
	StatusTexture[1] = (char*)"                  *YVXKKZ#QbZd9EgMIL";
	StatusTexture[2] = (char*)"              ,}m03^^^YK9@q}vryPd3R#BB8M}))rr_";
	StatusTexture[3] = (char*)"  `!)xTyIGdDgx**<;=!!!Yv~!,_----=r_Q###@@@@@@#B^";
	StatusTexture[4] = (char*)"-PI#@@##@@#Dg-.-:GoxjoLm:P}hyuoz-_L@###@@@@##@@B*";
	StatusTexture[5] = (char*)"^#B@BQBB#Q@@#:..:#YxddUETg30oK9X-6BB#@B8#@@####@x";
	StatusTexture[6] = (char*)" X##0@#Q###@@Hrr*****rrr)rrr))))V@g@#Q@#O8#BQ80e";
	StatusTexture[7] = (char*)"    :X68ZXZT                    *Pdm90My`";
	
	StatusTexture2[0] = (char*)"   ....:*********...:VVVV*";
	StatusTexture2[1] = (char*)"*VVVVVVFMMMMMMMMIVVVIMIMMIVVV:";
	StatusTexture2[2] = (char*)"*IMMMMMMFIIIIMMMMMMIIIIIMMMMIIV:.::";
	StatusTexture2[3] = (char*)"*IIIIIIIIIIFFFIIIFIFFFFIMMMNNIIFVV*";
	StatusTexture2[4] = (char*)"*IIIIIIIIIIFFFIFIFFFFFFIFIIIIFIFIIFV***:";
	StatusTexture2[5] = (char*)"*IIFFIIVVVVVVVFIIIIFFFIIFIIIIIIFIIIIIIIIIFV*";
	StatusTexture2[6] = (char*)"*IIFFFIMNNNNNNMIIIIFFFIIFFFFFIIFIMMNNNNNMMI*V:";
	StatusTexture2[7] = (char*)"*IIIIIMN$NMMMNNNIIIIIIIMIIIIIIMIIMNNMMMNNMVVM:";
	StatusTexture2[8] = (char*)":****VVF$IN$INNVVVVVVVVVVVVVVVVV**$MM$MM$*..*.";
	StatusTexture2[9] = (char*)"       :VNNMNM*                   *MNMNM*";
	StatusTexture2[10] = (char*)"         *****                     ****";


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
	PHP = ObjectManager::GetInstance()->GetPlayer()->GetHP();
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
	if (Progress < 4000)
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

	int Pro = Progress / 200;
	CursorManager::GetInstance()->WriteBuffer(53 + Pro * 2, 0, (char*)"플레", 9);
	CursorManager::GetInstance()->WriteBuffer(53 + Pro * 2, 1, (char*)"이어", 12);
	
	for (int i = 0; i < 13; ++i)
		CursorManager::GetInstance()->WriteBuffer(30, 31 + i, SBox[i], PHP == ObjectManager::GetInstance()->GetPlayer()->GetHP() ? 15 : 12);


	if (!ObjectManager::GetInstance()->GetPlayer()->GetIndex())
	{
		for(int i = 0; i < 8; ++i)
			CursorManager::GetInstance()->WriteBuffer(44, 33 + i, StatusTexture[i], 10);

		if (PHP <= 180)
		{
			CursorManager::GetInstance()->WriteBuffer(44, 35, (char*)"              ,}m03", 12);
			CursorManager::GetInstance()->WriteBuffer(44, 36, (char*)"  `!)xTyIGdDgx**", 12);
		}

		if (PHP <= 160)
		{
			CursorManager::GetInstance()->WriteBuffer(76, 39, (char*)"V@g@#Q@#", 12);
			CursorManager::GetInstance()->WriteBuffer(76, 40, (char*)"*Pdm90My`", 12);
		}

		if (PHP <= 140)
		{
			CursorManager::GetInstance()->WriteBuffer(44, 37, (char*)"-PI#@@##@@#Dg", 12);
			CursorManager::GetInstance()->WriteBuffer(44, 38, (char*)"^#B@BQBB", 12);
			CursorManager::GetInstance()->WriteBuffer(57, 39, (char*)"Hrr*****rrr)", 12);
		}
		
		if (PHP <= 120)
		{
			CursorManager::GetInstance()->WriteBuffer(76, 38, (char*)"-6BB#@B8#@@####@x", 12);
			CursorManager::GetInstance()->WriteBuffer(57, 39, (char*)"Hrr*****rrr)rrr))))V@g@#Q@#O8#BQ80e", 12);
		}
		
		if (PHP <= 100)
		{
			CursorManager::GetInstance()->WriteBuffer(44, 33, (char*)"                        :}L}!", 12);
			CursorManager::GetInstance()->WriteBuffer(44, 34, (char*)"                  *YVXKKZ#QbZd9", 12);
			CursorManager::GetInstance()->WriteBuffer(80, 37, (char*)"###@@@@##@@B*", 12);
		}
		
		if (PHP <= 80)
		{
			CursorManager::GetInstance()->WriteBuffer(61, 37, (char*)"GoxjoLm:P}h", 12);
			CursorManager::GetInstance()->WriteBuffer(60, 38, (char*)":#YxddUETg30", 12);
		}
		
		if (PHP <= 60)
		{
			CursorManager::GetInstance()->WriteBuffer(44, 39, (char*)" X##0@#Q###", 12);
			CursorManager::GetInstance()->WriteBuffer(44, 40, (char*)"    :X68ZXZT", 12);
			CursorManager::GetInstance()->WriteBuffer(32, 32, (char*)"D A N G E R ! !", 12);
		}

		if (PHP <= 40)
		{
			CursorManager::GetInstance()->WriteBuffer(44, 34, (char*)"                  *YVXKKZ#QbZd9EgMIL", 12);
			CursorManager::GetInstance()->WriteBuffer(70, 35, (char*)"q}vryPd3R#BB8", 12);
			CursorManager::GetInstance()->WriteBuffer(63, 36, (char*)"!!!Yv~!,_----=r", 12);
		}
		
		if (PHP <= 20)
		{
			CursorManager::GetInstance()->WriteBuffer(63, 36, (char*)"!!!Yv~!,_----=r_Q###@@@", 12);
			CursorManager::GetInstance()->WriteBuffer(44, 38, (char*)"^#B@BQBB#Q@@#:..:#YxddUETg30oK9X-6BB#@B8#@@####@x", 12);
			CursorManager::GetInstance()->WriteBuffer(44, 39, (char*)" X##0@#Q###@@Hrr*****rrr)rrr))))V@g@#Q@#O8#BQ80e", 12);
		}

		
		if (((Player*)ObjectManager::GetInstance()->GetPlayer())->GetArmor())
		{
			for (int i = 0; i < 8; ++i)
				CursorManager::GetInstance()->WriteBuffer(44, 33 + i, StatusTexture[i], 9);
			CursorManager::GetInstance()->WriteBuffer(32, 33, (char*)"A R M O R E D", 9);
		}		
	}
	else if (ObjectManager::GetInstance()->GetPlayer()->GetIndex())
	{
		for (int i = 0; i < 11; ++i)
			CursorManager::GetInstance()->WriteBuffer(46, 32 + i, StatusTexture2[i], 10);

		if (PHP <= 385)
			CursorManager::GetInstance()->WriteBuffer(65, 37, (char*)"FFFIIF", 12);
		if (PHP <= 370)
			CursorManager::GetInstance()->WriteBuffer(65, 38, (char*)"FFFIIFFF", 12);		
		if (PHP <= 355)
			CursorManager::GetInstance()->WriteBuffer(46, 32, (char*)"   ....:**", 12);
		if (PHP <= 340)
			CursorManager::GetInstance()->WriteBuffer(46, 33, (char*)"*VVVVVVF", 12);
		if (PHP <= 325)
			CursorManager::GetInstance()->WriteBuffer(46, 34, (char*)"*IMMM", 12);
		if (PHP <= 310)
			CursorManager::GetInstance()->WriteBuffer(46, 36, (char*)"*IIIIIIII", 12);
		if (PHP <= 295)
			CursorManager::GetInstance()->WriteBuffer(46, 37, (char*)"*IIFFII", 12);		
		if (PHP <= 280)
			CursorManager::GetInstance()->WriteBuffer(88, 38, (char*)"I*V:", 12);
		if (PHP <= 265)
			CursorManager::GetInstance()->WriteBuffer(87, 39, (char*)"MVVM:", 12);
		if (PHP <= 250)
			CursorManager::GetInstance()->WriteBuffer(88, 40, (char*)"..*.", 12);
		if (PHP <= 235)
			CursorManager::GetInstance()->WriteBuffer(65, 32, (char*)".:VVVV*", 12);
		if (PHP <= 220)
			CursorManager::GetInstance()->WriteBuffer(66, 33, (char*)"IMMIVVV", 12);
		if (PHP <= 205)
			CursorManager::GetInstance()->WriteBuffer(62, 34, (char*)"MMMIII", 12);
		if (PHP <= 190)
			CursorManager::GetInstance()->WriteBuffer(61, 40, (char*)"VVVVVVVVVVVVVVVVVV", 12);
		if (PHP <= 175)
			CursorManager::GetInstance()->WriteBuffer(84, 37, (char*)"IIIFV*", 12);
		if (PHP <= 160)
			CursorManager::GetInstance()->WriteBuffer(81, 38, (char*)"NNNNNMM", 12);
		if (PHP <= 145)
			CursorManager::GetInstance()->WriteBuffer(46, 40, (char*)":****VV", 12);
		if (PHP <= 130)
			CursorManager::GetInstance()->WriteBuffer(46, 39, (char*)"*IIIIIMN", 12);
		if (PHP <= 115)
			CursorManager::GetInstance()->WriteBuffer(46, 38, (char*)"*IIFFFIMN", 12);
		if (PHP <= 100)
			CursorManager::GetInstance()->WriteBuffer(68, 34, (char*)"IIMMMMIIV:.::", 12);
		if (PHP <= 85)
			CursorManager::GetInstance()->WriteBuffer(73, 35, (char*)"NNIIFVV*", 12);
		if (PHP <= 70)
		{
			CursorManager::GetInstance()->WriteBuffer(80, 39, (char*)"NNMMMNN", 12);
			CursorManager::GetInstance()->WriteBuffer(79, 40, (char*)"*$MM$MM$*", 12);
			CursorManager::GetInstance()->WriteBuffer(80, 41, (char*)"*MNMNM*", 12);
			CursorManager::GetInstance()->WriteBuffer(81, 42, (char*)"****", 12);
			CursorManager::GetInstance()->WriteBuffer(32, 32, (char*)"D A N G E R ! !", 12);
		}
		if (PHP <= 55)
		{
			CursorManager::GetInstance()->WriteBuffer(46, 35, (char*)"*IIIIIIIIIIFF", 12);
			CursorManager::GetInstance()->WriteBuffer(60, 39, (char*)"NNIIIIIIMIIII", 12);
		}
		if (PHP <= 40)
		{
			CursorManager::GetInstance()->WriteBuffer(75, 36, (char*)"IFIFIIFV**:", 12);
			CursorManager::GetInstance()->WriteBuffer(76, 37, (char*)"IIFIIIIII", 12);
			CursorManager::GetInstance()->WriteBuffer(77, 38, (char*)"IFIMM", 12);
			CursorManager::GetInstance()->WriteBuffer(76, 39, (char*)"IMIIM", 12);
		}
		if (PHP <= 25)
		{
			CursorManager::GetInstance()->WriteBuffer(53, 37, (char*)"VVVVV", 12);
			CursorManager::GetInstance()->WriteBuffer(54, 38, (char*)"NNNNNNMI", 12);
			CursorManager::GetInstance()->WriteBuffer(56, 32, (char*)"*******..", 12);
		}
		if (PHP <= 10)
		{
			CursorManager::GetInstance()->WriteBuffer(46, 33, (char*)"*VVVVVVFMMMMMMMMIVVVIMIMMIVVV:", 12);
			CursorManager::GetInstance()->WriteBuffer(59, 35, (char*)"FIIIFIFFF", 12);
			CursorManager::GetInstance()->WriteBuffer(55, 36, (char*)"IIFFFIFIFFFF", 12);
			CursorManager::GetInstance()->WriteBuffer(58, 37, (char*)"VVFIIII", 12);
			CursorManager::GetInstance()->WriteBuffer(62, 38, (char*)"IIIFFFIIFFFFFII", 12);
			CursorManager::GetInstance()->WriteBuffer(73, 39, (char*)"III", 12);
		}


		if (((Player*)ObjectManager::GetInstance()->GetPlayer())->GetArmor())
		{
			for (int i = 0; i < 11; ++i)
				CursorManager::GetInstance()->WriteBuffer(46, 32 + i, StatusTexture2[i], 9);
			CursorManager::GetInstance()->WriteBuffer(32, 33, (char*)"A R M O R E D", 9);
		}			
	}
}

void Stage::Release()
{
}
