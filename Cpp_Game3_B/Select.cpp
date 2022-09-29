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
	Buffer[0] = (char*)"┌ㅡㅡ┐";
	Buffer[1] = (char*)"ㅣ ▲ ㅣ";
	Buffer[2] = (char*)"└ㅡㅡ┘";
	Buffer[3] = (char*)"┌ㅡㅡ┐";
	Buffer[4] = (char*)"ㅣ ◀ ㅣ";
	Buffer[5] = (char*)"└ㅡㅡ┘";
	Buffer[6] = (char*)"┌ㅡㅡ┐";
	Buffer[7] = (char*)"ㅣ ▼ ㅣ";
	Buffer[8] = (char*)"└ㅡㅡ┘";
	Buffer[9] = (char*)"┌ㅡㅡ┐";
	Buffer[10] = (char*)"ㅣ ▶ ㅣ";
	Buffer[11] = (char*)"└ㅡㅡ┘";
	Buffer[12] = (char*)"┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐";
	Buffer[13] = (char*)"ㅣ       SPACE        ㅣ";
	Buffer[14] = (char*)"└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘";
	Buffer[15] = (char*)"┌ㅡㅡ┐";
	Buffer[16] = (char*)"ㅣ R  ㅣ";
	Buffer[17] = (char*)"└ㅡㅡ┘";
	Buffer[15] = (char*)"┌ㅡㅡ┐";
	Buffer[16] = (char*)"ㅣ T  ㅣ";
	Buffer[17] = (char*)"└ㅡㅡ┘";
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

		CursorManager::GetInstance()->WriteBuffer(8, 7, (char*)"┌─────────────────────────────────────────────────────────────────┐");
		CursorManager::GetInstance()->WriteBuffer(8, 8, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 9, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 10, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 11, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 12, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 13, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 14, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 15, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 16, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 17, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 18, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 19, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 20, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 21, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 22, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 23, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 24, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 25, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 26, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 27, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 28, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 29, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 30, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 31, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 32, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 33, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 34, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 35, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 36, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 37, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 38, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 39, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 40, (char*)"│                                                                                                                                  │");
		CursorManager::GetInstance()->WriteBuffer(8, 41, (char*)"└─────────────────────────────────────────────────────────────────┘");

		CursorManager::GetInstance()->WriteBuffer(8, 9, (char*)"조작 :", 14);
		CursorManager::GetInstance()->WriteBuffer(8, 10, (char*)"W , A, S, D 키는 각각 상, 하, 좌, 우로 이동할때 사용합니다.");
		CursorManager::GetInstance()->WriteBuffer(8, 11, (char*)"SPACE BAR 키로 총알을 발사할 수 있으며 화살표를 함께 눌러 발사할 방향을 지정할 수 있습니다.");
		CursorManager::GetInstance()->WriteBuffer(8, 12, (char*)"스킬 게이지가 가득 차면 스킬을 사용할 수 있습니다.");
		CursorManager::GetInstance()->WriteBuffer(8, 13, (char*)"1스킬 : R키로 발동, 플레이어의 좌, 우 차선에 스파이크 스트립 설치를 요청해 밟는 모든 차량에 큰 피해를 줍니다.");
		CursorManager::GetInstance()->WriteBuffer(8, 13, (char*)"2스킬 : T키로 발동, 드론 공중지원을 요청합니다. 드론은 일정 시간동안 적을 사격합니다.");

	}
	if (!Guide)
	{
		CursorManager::GetInstance()->WriteBuffer(24, 1, (char*)" ___ ___         __     __        __             _______         __              __   __", 14);
		CursorManager::GetInstance()->WriteBuffer(24, 2, (char*)"|   |   |.-----.|  |--.|__|.----.|  |.-----.    |     __|.-----.|  |.-----.----.|  |_|__|.-----.-----.", 14);
		CursorManager::GetInstance()->WriteBuffer(24, 3, (char*)"|   |   ||  -__||     ||  ||  __||  ||  -__|    |__     ||  -__||  ||  -__|  __||   _|  ||  _  |     |", 14);
		CursorManager::GetInstance()->WriteBuffer(24, 4, (char*)" |_____/ |_____||__|__||__||____||__||_____|    |_______||_____||__||_____|____||____|__||_____|__|__|", 14);

		CursorManager::GetInstance()->WriteBuffer(6, 9, (char*)"┌───────────────────────────────┐", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 10, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 11, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 12, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 13, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 14, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 15, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 16, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 17, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 18, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 19, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 20, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 21, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 22, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 23, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 24, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 25, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 26, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 27, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 28, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 29, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 30, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 31, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 32, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 33, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 34, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 35, (char*)"│                                                              │", !Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(6, 36, (char*)"└───────────────────────────────┘", !Index ? 10 : 8);

		CursorManager::GetInstance()->WriteBuffer(78, 9, (char*)"┌───────────────────────────────┐", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 10, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 11, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 12, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 13, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 14, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 15, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 16, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 17, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 18, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 19, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 20, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 21, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 22, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 23, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 24, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 25, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 26, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 27, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 28, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 29, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 30, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 31, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 32, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 33, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 34, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 35, (char*)"│                                                              │", Index ? 10 : 8);
		CursorManager::GetInstance()->WriteBuffer(78, 36, (char*)"└───────────────────────────────┘", Index ? 10 : 8);
	}
}
              



void Select::Release()
{
}
