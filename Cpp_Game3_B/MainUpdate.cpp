#include "MainUpdate.h"
#include "CursorManager.h"
#include "PrototypeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Start()
{
	CursorManager::GetInstance()->CreateBuffer(150, 44);
	PrototypeManager::GetInstance()->Initialize();

	SceneManager::GetInstance()->SetScene(SCENEID::LOGO);
}

void MainUpdate::Update()
{
	CursorManager::GetInstance()->FlippingBuffer();
	InputManager::GetInstance()->CheckKey();
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
}