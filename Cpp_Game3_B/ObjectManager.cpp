#include "ObjectManager.h"
#include "ObjectpoolManager.h"
#include "Player.h"
#include "BackGround.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr), pBG(nullptr)
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject(string _Key)
{
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);

	ObjectpoolManager::GetInstance()->SwitchingObject(_Key);
}

void ObjectManager::AddObject(string _Key, Vector3 _Position)
{
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);

	ObjectpoolManager::GetInstance()->SwitchingObject(_Key, _Position);
}

void ObjectManager::Update()
{
	pBG->Update();
	pPlayer->Update();
	ObjectpoolManager::GetInstance()->Update();
}

void ObjectManager::Render()
{
	pBG->Render();
	pPlayer->Render();
	ObjectpoolManager::GetInstance()->Render();
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pBG;
	pBG = nullptr;
}