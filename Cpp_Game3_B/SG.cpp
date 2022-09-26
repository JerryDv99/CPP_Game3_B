#include "SG.h"
#include "Bullet.h"
#include "Player.h"
#include "CursorManager.h"
#include "ObjectManager.h"

SG::SG()
{
}

SG::~SG()
{
}

void SG::Start()
{
	Release();
}

int SG::Update(Transform& _Transform)
{
	if (pObject)
	{
		pObject->SetPosition(pObject->GetPosition() += pObject->GetDirection() * (pObject->GetSpeed() * 1.2f));
		if (pObject->GetDirection().x * pObject->GetDirection().x >= 1 && (pObject->GetDirection().y >= -0.15 && pObject->GetDirection().y <= 0.15))
			pObject->SetPosition(pObject->GetPosition() += pObject->GetDirection() * (pObject->GetSpeed() * 1.8f));

		if (!pObject->GetIndex() && ObjectManager::GetInstance()->Collision("Enemy", pObject))
		{
			Object* pObj = ObjectManager::GetInstance()->GetCollObj("Enemy", pObject);

			if(((Player*)ObjectManager::GetInstance()->GetPlayer())->GetBuff() == 2)
				pObj->ReduceHP(60);
			else
				pObj->ReduceHP(40);
			
			return 1;
		}
	}	

	return 0;
}

void SG::Render()
{
	if (pObject)
		CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), (char*)"¡Ü", pObject->GetIndex() ? 12 : 14);
}

void SG::Release()
{
	delete pObject;
	pObject = nullptr;
}
