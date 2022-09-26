#include "MG.h"
#include "Bullet.h"
#include "Player.h"
#include "Object.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"

MG::MG()
{
}

MG::~MG()
{
}

void MG::Start()
{
	Release();
}

int MG::Update(Transform& _Transform)
{
	if (pObject)
	{
		pObject->SetPosition(pObject->GetPosition() += pObject->GetDirection() * (pObject->GetSpeed() * 2.2f));
		if (pObject->GetDirection().x * pObject->GetDirection().x >= 1 && (pObject->GetDirection().y >= -0.15 && pObject->GetDirection().y <= 0.15))
			pObject->SetPosition(pObject->GetPosition() += pObject->GetDirection() * (pObject->GetSpeed() * 3.4f));

		if (pObject->GetIndex() && ObjectManager::GetInstance()->Collision("Player", pObject))
		{
			Object* pObj = ObjectManager::GetInstance()->GetPlayer();
			if (((Player*)ObjectManager::GetInstance()->GetPlayer())->GetArmor())
				((Player*)pObj)->ReduceArmor(5);
			else
				pObj->ReduceHP(5);
			return 1;
		}
	}

	return 0;
}

void MG::Render()
{
	if(pObject)
		CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), (char*)"=", 12);
}

void MG::Release()
{
	delete pObject;
	pObject = nullptr;
}
