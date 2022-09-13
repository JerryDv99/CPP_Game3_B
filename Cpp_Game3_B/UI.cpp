#include "UI.h"
#include "ScrollBox.h"
#include "CursorManager.h"

UI::UI()
{
}

UI::~UI()
{
	Release();
}

Object* UI::Start(string _Key)
{
	Key = _Key;

	//Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(150.0f, 8.0f);

	Box = new ScrollBox;
	Box->Start();
	Box->SetPosition(int(Info.Position.x - (Info.Scale.x / 2)), int(Info.Position.y - (Info.Scale.y / 2)));
	Box->SetBoxSize(Info.Scale.x, Info.Scale.y);

	return nullptr;
}

int UI::Update()
{
	Box->Update();
	return 0;
}

void UI::Render()
{
	Box->Render();
}

void UI::Release()
{
}
