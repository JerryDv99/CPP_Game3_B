#include "SG.h"
#include "Bullet.h"
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
}

int SG::Update(Transform& _Transform)
{
	pObject->SetPosition(pObject->GetPosition() += pObject->GetDirection() * (pObject->GetSpeed() * 1.2f));
	if (pObject->GetDirection().x * pObject->GetDirection().x >= 1 && (pObject->GetDirection().y >= - 0.15 && pObject->GetDirection().y <= 0.15))
		pObject->SetPosition(pObject->GetPosition() += pObject->GetDirection() * (pObject->GetSpeed() * 1.8f));

	if (!pObject->GetIndex() && ObjectManager::GetInstance()->Collision("Enemy", pObject))
	{
		Object* pObj = ObjectManager::GetInstance()->GetCollObj("Enemy", pObject);
		pObj->SetHP(pObj->GetHP() - 80);
		return 1;
	}

	return 0;
}

void SG::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"¡Ü", pObject->GetIndex() ? 12 : 14);
}

void SG::Release()
{
}
