#include "Select.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"

Select::Select() : Guide(false), Time(0), Index(0)
{
}

Select::~Select()
{
	Release();
}

void Select::Start()
{
	Index = 0;
	Guide = true;
	Buffer[0] = (char*)"忙天天忖";
	Buffer[1] = (char*)"太 ～ 太";
	Buffer[2] = (char*)"戌天天戎";
	Buffer[3] = (char*)"忙天天忖";
	Buffer[4] = (char*)"太 ９ 太";
	Buffer[5] = (char*)"戌天天戎";
	Buffer[6] = (char*)"忙天天忖";
	Buffer[7] = (char*)"太 ∪ 太";
	Buffer[8] = (char*)"戌天天戎";
	Buffer[9] = (char*)"忙天天忖";
	Buffer[10] = (char*)"太 Ⅱ 太";
	Buffer[11] = (char*)"戌天天戎";
	Buffer[12] = (char*)"忙天天天天天天天天天天忖";
	Buffer[13] = (char*)"太       SPACE        太";
	Buffer[14] = (char*)"戌天天天天天天天天天天戎";
	Buffer[15] = (char*)"忙天天忖";
	Buffer[16] = (char*)"太 R  太";
	Buffer[17] = (char*)"戌天天戎";
	Buffer[15] = (char*)"忙天天忖";
	Buffer[16] = (char*)"太 T  太";
	Buffer[17] = (char*)"戌天天戎";
	Time = GetTickCount64();
}

void Select::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (Guide && dwKey & KEY_R)
		Guide = false;
	if ((dwKey & KEY_RIGHT || dwKey & KEY_ARIGHT) && !Index)
		Index = true;
	if ((dwKey & KEY_LEFT || dwKey & KEY_ALEFT) && Index)
		Index = false;
	if (Time + 100 < GetTickCount64() && dwKey & KEY_RETURN)
		switch (Index)
		{
		case 0:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
			break;
		case 1:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
			ObjectManager::GetInstance()->GetPlayer()->SetIndex(Index);
			ObjectManager::GetInstance()->GetPlayer()->SetHP(400);
			break;
		}

}
        
  

        
 
 
 

void Select::Render()
{
	if (Guide)
	{
		CursorManager::GetInstance()->WriteBuffer(42, 1, (char*)",--. ,--.                          ,----.           ,--.   ,--.", 11);
		CursorManager::GetInstance()->WriteBuffer(42, 2, (char*)"|  | |  |  ,---. ,---. ,--.--.    '  .-./   ,--.,--.`--' ,-|  | ,---.", 11);
		CursorManager::GetInstance()->WriteBuffer(42, 3, (char*)"|  | |  | (  .-'| .-. :|  .--'    |  | .---.|  ||  |,--.' .-. || .-. :", 11);
		CursorManager::GetInstance()->WriteBuffer(42, 4, (char*)"'  '-'  '.-'  `)|   --.|  |       '  '--'  |'  ''  '|  || `-' ||   --.", 11);
		CursorManager::GetInstance()->WriteBuffer(42, 5, (char*)" `-----' `----'  `----'`--'        `------'  `----' `--' `---'  `----'", 11);

		CursorManager::GetInstance()->WriteBuffer(8, 7, (char*)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
		CursorManager::GetInstance()->WriteBuffer(8, 8, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 9, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 10, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 11, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 12, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 13, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 14, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 15, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 16, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 17, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 18, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 19, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 20, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 21, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 22, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 23, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 24, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 25, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 26, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 27, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 28, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 29, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 30, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 31, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 32, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 33, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 34, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 35, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 36, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 37, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 38, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 39, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 40, (char*)"弛                                                                                                                                  弛");
		CursorManager::GetInstance()->WriteBuffer(8, 41, (char*)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");



	}
	if (!Guide)
	{
		CursorManager::GetInstance()->WriteBuffer(24, 1, (char*)" ___ ___         __     __        __             _______         __              __   __", 14);
		CursorManager::GetInstance()->WriteBuffer(24, 2, (char*)"|   |   |.-----.|  |--.|__|.----.|  |.-----.    |     __|.-----.|  |.-----.----.|  |_|__|.-----.-----.", 14);
		CursorManager::GetInstance()->WriteBuffer(24, 3, (char*)"|   |   ||  -__||     ||  ||  __||  ||  -__|    |__     ||  -__||  ||  -__|  __||   _|  ||  _  |     |", 14);
		CursorManager::GetInstance()->WriteBuffer(24, 4, (char*)" |_____/ |_____||__|__||__||____||__||_____|    |_______||_____||__||_____|____||____|__||_____|__|__|", 14);

		CursorManager::GetInstance()->WriteBuffer(6, 9, (char*)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 10, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 11, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 12, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 13, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 14, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 15, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 16, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 17, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 18, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 19, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 20, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 21, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 22, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 23, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 24, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 25, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 26, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 27, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 28, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 29, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 30, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 31, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 32, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 33, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 34, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 35, (char*)"弛                                                              弛", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 36, (char*)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎", !Index ? 10 : 8);

		CursorManager::GetInstance()->WriteBuffer(78, 9, (char*)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 10, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 11, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 12, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 13, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 14, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 15, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 16, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 17, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 18, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 19, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 20, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 21, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 22, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 23, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 24, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 25, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 26, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 27, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 28, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 29, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 30, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 31, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 32, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 33, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 34, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 35, (char*)"弛                                                              弛", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 36, (char*)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎", Index ? 10 : 8);
	}
}
              



void Select::Release()
{
}
