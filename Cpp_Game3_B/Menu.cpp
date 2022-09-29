#include "Menu.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "SceneManager.h"

Menu::Menu() : Time(0), Cursor(0)
{
}

Menu::~Menu()
{
}

void Menu::Start()
{
	Cursor = 23;
	Time = GetTickCount64();

	Buffer[0] = (char*)"----    ---- --------  ------------ ----    ---- ---      ---    ------ ---      ---  ------------ ----    ----    ------    ------------ ------------";
	Buffer[1] = (char*)"****    **** ********  ************ ****    **** ***  **  ***   ******** ***    ***   ************ ****    ****   ********   ************ ************";
	Buffer[2] = (char*)"----    ----   ----    ----         ----    ---- ---  --  ---  ----------  ---  ---    ---         ----    ----  ----------  ----         ----";
	Buffer[3] = (char*)"************   ****    ****  ****** ************ ***  **  *** ****    **** ******     ***          ************ ****    **** ************ ************";
	Buffer[4] = (char*)"------------   ----    ----  ------ ------------ ---  --  --- ------------  ----      ---          ------------ ------------ ------------ ------------";
	Buffer[5] = (char*)"****    ****   ****    ****    **** ****    **** ************ ************  ****      ***          ****    **** ************        ***** ****";
	Buffer[6] = (char*)"----    ---- --------  ------------ ----    ----  ----------  ----    ----  ----      ------------ ----    ---- ----    ---- ------------ ------------";
	Buffer[7] = (char*)"****    **** ********  ************ ****    ****   ********   ****    ****  ****      ************ ****    **** ****    **** ************ ************";
	Buffer[8] = (char*)"         `gg,";
	Buffer[9] = (char*)"         `BB_";
	Buffer[10] = (char*)" ,:     -Q@@#:     ,:";
	Buffer[11] = (char*)"-Q@MmmmmB@@@@#mmmm3##-";
	Buffer[12] = (char*)"   U@@@@@@@@@@@@@@d`";
	Buffer[13] = (char*)"    V@@@@@@@@@@@@H";
	Buffer[14] = (char*)"    y@@@@@@@@@@@@W";
	Buffer[15] = (char*)"   m@@@@@@@@@@@@@@O`";
	Buffer[16] = (char*)"-B@WIIIIQ@@@@#IIIIm@#-";
	Buffer[17] = (char*)" _:     -Q@@B,     _,:";
	Buffer[18] = (char*)"         `BB_";
	Buffer[19] = (char*)"         `$$,";
	Buffer[20] = (char*)"         _____㏑㏑㏑㏑㏑㏑";
	Buffer[21] = (char*)"        /";
	Buffer[22] = (char*)"       /";
	Buffer[23] = (char*)"      /";
	Buffer[24] = (char*)"忙式式式式式式式式式式式式";
	Buffer[25] = (char*)"弛";
	Buffer[26] = (char*)"弛 ㏑㏑㏑㏑";
	Buffer[27] = (char*)"弛 ㏑㏑㏑㏑";
	Buffer[28] = (char*)"弛";
}
 
void Menu::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (Cursor > 23)
	{
		if ((dwKey & KEY_AUP || dwKey & KEY_UP) && Time + 100 < GetTickCount64())
		{
			Cursor -= 3;
			Time = GetTickCount64();
		}		
	}
	if (Cursor < 29)
	{
		if ((dwKey & KEY_ADOWN || dwKey & KEY_DOWN) && Time + 100 < GetTickCount64())
		{
			Cursor += 3;
			Time = GetTickCount64();
		}
	}
	if (dwKey & KEY_RETURN && Time + 200 < GetTickCount64())
	{
		switch (Cursor)
		{
		case 23:
			SceneManager::GetInstance()->SetScene(SCENEID::SELECT);
			break;
		case 26:
			
			break;
		case 29:
			exit(NULL);
			break;
		}
	}
}

void Menu::Render()
{
	for (int i = 0; i < 8; i += 2)
		CursorManager::GetInstance()->WriteBuffer(0, 5 + i, Buffer[i], 14);
	for (int i = 1; i < 8; i += 2)
	{
		if (GetTickCount64() % 3000 < 1500)
			CursorManager::GetInstance()->WriteBuffer(0, 5 + i, Buffer[i], 14);
		if (GetTickCount64() % 3000 >= 1500)
			CursorManager::GetInstance()->WriteBuffer(0, 5 + i, Buffer[i], 12);
	}
	for (int i = 8; i < 20; ++i)
		CursorManager::GetInstance()->WriteBuffer(15, 8 + i, Buffer[i], 14);
	for (int i = 20; i < 29; ++i)
		CursorManager::GetInstance()->WriteBuffer(124, 15 + i, Buffer[i], 3);
	if (GetTickCount64() % 2000 < 1000)
		CursorManager::GetInstance()->WriteBuffer(138, 35, "㏑㏑㏑㏑㏑㏑", 12);
	if (GetTickCount64() % 2000 >= 1000)
		CursorManager::GetInstance()->WriteBuffer(138, 35, "㏑㏑㏑㏑㏑㏑", 9);

	CursorManager::GetInstance()->WriteBuffer(126, 41, "㏑", 14);
	CursorManager::GetInstance()->WriteBuffer(126, 42, "㏑", 14);
	CursorManager::GetInstance()->WriteBuffer(128, 41, "㏑㏑㏑", 12);
	CursorManager::GetInstance()->WriteBuffer(128, 42, "㏑㏑㏑", 12);

	CursorManager::GetInstance()->WriteBuffer(58, 20, "忙式式式式式式式式式式式式式式式忖");
	CursorManager::GetInstance()->WriteBuffer(58, 21, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 22, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 23, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 24, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 25, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 26, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 27, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 28, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 29, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 30, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 31, "弛                              弛");
	CursorManager::GetInstance()->WriteBuffer(58, 32, "戌式式式式式式式式式式式式式式式戎");

	CursorManager::GetInstance()->WriteBuffer(70, 23, "GAME START", 8);
	CursorManager::GetInstance()->WriteBuffer(72, 26, "OPTION", 8);
	CursorManager::GetInstance()->WriteBuffer(73, 29, "EXIT", 8);
	switch (Cursor)
	{
	case 23:
		CursorManager::GetInstance()->WriteBuffer(70, 23, "GAME START");
		break;
	case 26:
		CursorManager::GetInstance()->WriteBuffer(72, 26, "OPTION");
		break;
	case 29:
		CursorManager::GetInstance()->WriteBuffer(73, 29, "EXIT");
		break;
	}
}

void Menu::Release()
{
}
