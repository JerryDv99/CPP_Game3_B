#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "PrototypeManager.h"
#include "ObjectManager.h"
#include "ObjectpoolManager.h"
#include "InputManager.h"
#include "BackGround.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Start()
{
	Object* pObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();
	Object* pBG = PrototypeManager::GetInstance()->FindObject("BackGround")->Clone();

	if (pObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(pObj);
	
	if (pBG != nullptr)
		ObjectManager::GetInstance()->SetBG(pBG);


}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
}
