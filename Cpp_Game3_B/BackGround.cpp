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

    Texture[0] = (char*)"быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбы";
    Texture[1] = (char*)"быбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбы";
    Texture[2] = (char*)"быбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбы";
    Texture[3] = (char*)"быбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы";
    Texture[4] = (char*)"быбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы";
    Texture[5] = (char*)"бы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы";
    Texture[6] = (char*)"            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы";
    Texture[7] = (char*)"          быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы";
    Texture[8] = (char*)"        быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы";
    Texture[9] = (char*)"      быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы            быбыбыбыбыбы";
    Texture[10] = (char*)"быбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбыбы";
    Texture[11] = (char*)"в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞в╞";
    Texture[12] = (char*)"";
    
    return this;
}

int BackGround::Update()
{
    if (Count < 10)
        Count += 0.01f * ((Player*)ObjectManager::GetInstance()->GetPlayer())->GetSpeed();
    if (Count >= 10)
        Count = 0;
   
    return 0;
}

void BackGround::Render()
{
    CursorManager::GetInstance()->WriteBuffer(0, 2, Texture[11], 8);
    CursorManager::GetInstance()->WriteBuffer(0, 30, Texture[11], 8);
    CursorManager::GetInstance()->WriteBuffer(0, 9, Texture[(int)Count]);
    CursorManager::GetInstance()->WriteBuffer(0, 23, Texture[(int)Count]);
    CursorManager::GetInstance()->WriteBuffer(0, 16, Texture[10], 14);
}

void BackGround::Release()
{
}
