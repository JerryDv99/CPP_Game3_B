#include "ObjectManager.h"
#include "ObjectpoolManager.h"
#include "Player.h"
#include "BackGround.h"
#include "CollisionManager.h"

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
	ObjectpoolManager::GetInstance()->Update();
	pPlayer->Update();
}

void ObjectManager::Render()
{
	pBG->Render();
	ObjectpoolManager::GetInstance()->Render();
	pPlayer->Render();
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pBG;
	pBG = nullptr;
}

bool ObjectManager::Collision(string _C, string _T)
{
	if (_C == "Player" && ObjectpoolManager::GetInstance()->FindObject(_T))
	{
		list<Object*> iter = ObjectpoolManager::GetInstance()->GetList(_T);
		auto iterT = iter.begin();
		if (!iter.empty())
		{
			for (iterT; iterT != iter.end();)
			{
				if (CollisionManager::RectCollision(pPlayer->GetTransform(), (*iterT)->GetTransform()))
					return true;
				else
					++iterT;
			}
		}
		
	}
	if (ObjectpoolManager::GetInstance()->FindObject(_C) && ObjectpoolManager::GetInstance()->FindObject(_T))
	{
		list<Object*> iter = ObjectpoolManager::GetInstance()->GetList(_C);
		list<Object*> iter2 = ObjectpoolManager::GetInstance()->GetList(_T);		

		if (!iter.empty() && !iter2.empty())
		{
			auto iterC = iter.begin();
			auto iterT = iter2.begin();
			for (iterC; iterC != iter.end(); ++iterC)
			{
				for (iterT; iterT != iter2.end();)
				{
					if (CollisionManager::RectCollision((*iterC)->GetTransform(), (*iterT)->GetTransform()))
						return true;
					else
						++iterT;
				}
			}
		}		
	}

	return false;
}
