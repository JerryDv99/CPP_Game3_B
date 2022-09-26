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

Object* ObjectManager::GetObj(string _Key)
{
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);

	Object* pObj = ObjectpoolManager::GetInstance()->GetObj(_Key);

	return pObj;
}

Object* ObjectManager::SearchObj(string _Key)
{
	Object* pObj = ObjectpoolManager::GetInstance()->SearchObj("Enemy");

	if (pObj)
		return pObj;
	return nullptr;
}

void ObjectManager::PutEnable(string _Key, Object* _Obj)
{
	if (ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->PutEnable(_Key, _Obj);
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
	else if (ObjectpoolManager::GetInstance()->FindObject(_C) && ObjectpoolManager::GetInstance()->FindObject(_T))
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

Object* ObjectManager::GetCollObj(string _C, Object* _Obj)
{	
	if (ObjectpoolManager::GetInstance()->FindObject(_C))
	{
		list<Object*> iter = ObjectpoolManager::GetInstance()->GetList(_C);
		if (!iter.empty())
		{
			auto iterC = iter.begin();
			for (iterC; iterC != iter.end(); ++iterC)
			{
				if (CollisionManager::RectCollision((*iterC)->GetTransform(), _Obj->GetTransform()))
					return (*iterC);
			}
		}
	}
	return nullptr;
}

bool ObjectManager::Collision(string _C, Object* _Obj)
{
	if (_C == "Player")
	{
		if (CollisionManager::RectCollision(pPlayer->GetTransform(), _Obj->GetTransform()))
			return true;
	}
	else if (ObjectpoolManager::GetInstance()->FindObject(_C))
	{
		list<Object*> iter = ObjectpoolManager::GetInstance()->GetList(_C);
		if (!iter.empty())
		{
			auto iterC = iter.begin();
			for (iterC; iterC != iter.end(); ++iterC)
			{
				if (CollisionManager::RectCollision((*iterC)->GetTransform(), _Obj->GetTransform()))
					return true;
			}
		}
	}
	
	return false;
}

bool ObjectManager::Collision(Object* _Obj, string _T)
{
	if (ObjectpoolManager::GetInstance()->FindObject(_T))
	{
		list<Object*> iter = ObjectpoolManager::GetInstance()->GetList(_T);
		if (!iter.empty())
		{
			auto iterT = iter.begin();
			for (iterT; iterT != iter.end(); ++iterT)
			{
				if (CollisionManager::RectCollision(_Obj->GetTransform(), (*iterT)->GetTransform()))
					return true;
			}
		}
	}
	return false;
}
