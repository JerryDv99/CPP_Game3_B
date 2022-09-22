#include "Pistol.h"
#include "Bullet.h"
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
    pObject->SetPosition(pObject->GetPosition() += pObject->GetDirection() * (pObject->GetSpeed() * 1.5f));
    if (pObject->GetDirection().x * pObject->GetDirection().x >= 1 && (pObject->GetDirection().y >= -0.15 && pObject->GetDirection().y <= 0.15))
        pObject->SetPosition(pObject->GetPosition() += pObject->GetDirection() * (pObject->GetSpeed() * 2.8f));

    return 0;
}

void Pistol::Render()
{
    CursorManager::GetInstance()->WriteBuffer(
        pObject->GetPosition(), (char*)"*", pObject->GetIndex() ? 12 : 14);
}

void Pistol::Release()
{
}
