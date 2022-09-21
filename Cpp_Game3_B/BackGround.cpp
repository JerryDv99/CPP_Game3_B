#include "BackGround.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "Player.h"

BackGround::BackGround()
{
}

BackGround::~BackGround()
{
}

Object* BackGround::Start(string _Key)
{
    Key = _Key;

    Info.Position = Vector3(0.0f, 0.0f);
    Info.Rotation = Vector3(0.0f, 0.0f);
    Info.Scale = Vector3(0.0f, 0.0f);
    Info.Direction = Vector3(0.0f, 0.0f);

    Count = 0;

    Target = nullptr;

    Texture[0] = (char*)"�������            �������            �������            �������            �������            �������            ����";
    Texture[1] = (char*)"������            �������            �������            �������            �������            �������            �����";
    Texture[2] = (char*)"�����            �������            �������            �������            �������            �������            ������";
    Texture[3] = (char*)"����            �������            �������            �������            �������            �������            �������";
    Texture[4] = (char*)"���            �������            �������            �������            �������            �������            �������";
    Texture[5] = (char*)"��            �������            �������            �������            �������            �������            �������";
    Texture[6] = (char*)"            �������            �������            �������            �������            �������            �������";
    Texture[7] = (char*)"          �������            �������            �������            �������            �������            �������";
    Texture[8] = (char*)"        �������            �������            �������            �������            �������            �������";
    Texture[9] = (char*)"      �������            �������            �������            �������            �������            �������";
    Texture[10] = (char*)"    �������            �������            �������            �������            �������            �������";
    Texture[11] = (char*)"  �������            �������            �������            �������            �������            �������";
    Texture[12] = (char*)"�������            �������            �������            �������            �������            �������";
    Texture[13] = (char*)"����������������������������������������������������������������������������";
    Texture[14] = (char*)"�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�";
    Texture[15] = (char*)"";
    
    return this;
}

int BackGround::Update()
{
    if (Count < 13)
        Count += 0.02f * ((Player*)ObjectManager::GetInstance()->GetPlayer())->GetSpeed();
    if (Count >= 13)
        Count = 0;
   
    return 0;
}

void BackGround::Render()
{
    CursorManager::GetInstance()->WriteBuffer(0, 2, Texture[14], 8);
    CursorManager::GetInstance()->WriteBuffer(0, 30, Texture[14], 8);
    CursorManager::GetInstance()->WriteBuffer(0, 9, Texture[(int)Count]);
    CursorManager::GetInstance()->WriteBuffer(0, 23, Texture[(int)Count]);
    CursorManager::GetInstance()->WriteBuffer(0, 16, Texture[13], 14);
}

void BackGround::Release()
{
}
