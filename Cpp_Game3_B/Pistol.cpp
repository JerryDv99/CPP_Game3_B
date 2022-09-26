#include "Pistol.h"
#include "Bullet.h"
#include "Player.h"
#include "ObjectManager.h"
#include "CursorManager.h"

Pistol::Pistol()
{
}

Pistol::~Pistol()
{
}

void Pistol::Start()
{
}

int Pistol::Update(Transform& _Transform)
{
    if (pObject)
    {
        pObject->SetPosition(pObject->GetPosition() += pObject->GetDirection() * (pObject->GetSpeed() * 1.5f));
        if (pObject->GetDirection().x * pObject->GetDirection().x >= 1 && (pObject->GetDirection().y >= -0.15 && pObject->GetDirection().y <= 0.15))
            pObject->SetPosition(pObject->GetPosition() += pObject->GetDirection() * (pObject->GetSpeed() * 2.8f));

        if (!pObject->GetIndex() && ObjectManager::GetInstance()->Collision("Enemy", pObject))
        {
            Object* pObj = ObjectManager::GetInstance()->GetCollObj("Enemy", pObject);

            if (((Player*)ObjectManager::GetInstance()->GetPlayer())->GetBuff() == 2)
                pObj->ReduceHP(15);
            else
                pObj->ReduceHP(10);

            return 1;
        }

        if (pObject->GetIndex() && ObjectManager::GetInstance()->Collision("Player", pObject))
        {
            Object* pObj = ObjectManager::GetInstance()->GetPlayer();
            if (((Player*)ObjectManager::GetInstance()->GetPlayer())->GetArmor())
                ((Player*)pObj)->ReduceArmor(10);
            else
                pObj->ReduceHP(10);
            return 1;
        }
        
    }  

    return 0;
}

void Pistol::Render()
{
    if(pObject)
        CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), (char*)"*", pObject->GetIndex() ? 12 : 14);
}

void Pistol::Release()
{
}
