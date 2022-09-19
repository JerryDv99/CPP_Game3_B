#include "ScrollBox.h"
#include "CursorManager.h"

ScrollBox::ScrollBox() : Width(0), Height(0)
{
}

ScrollBox::~ScrollBox()
{
}

void ScrollBox::Start()
{
	Key = "ScrollBox";

	Width = 2;
	Height = 1;

	EndPos = Vector3(StartPos.x + Width, StartPos.y + Height);

	WidthTexture = "";
	HeightTexture = (char*)"¦¢";

	Index = 0;

	Texture.push_back("¦£¦¡¦¤");
	Texture.push_back("¦¢¡¡¦¢");
	Texture.push_back("¦¦¦¡¦¥");
	End = 3;
}

void ScrollBox::Update()
{
}

void ScrollBox::Render()
{
	for (int i = 0; i < Texture.size(); ++i)
		CursorManager::GetInstance()->WriteBuffer(StartPos.x, StartPos.y + i, Texture[i], Index >= i ? 12 : 8);
}

void ScrollBox::Release()
{
}
