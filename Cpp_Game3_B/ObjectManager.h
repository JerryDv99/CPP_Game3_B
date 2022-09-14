#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	Object* pPlayer;
	Object* pBG;
public:
	Object* GetPlayer() const { return pPlayer; }
	void SetPlayer(Object* _Object) { pPlayer = _Object; }
	void SetBG(Object* _Object) { pBG = _Object; }
public:
	void AddObject(string _Key);
	void AddObject(string _Key, Vector3 _Position);
	void Update();
	void Render();
	void Release();
private:
	ObjectManager();
public:
	~ObjectManager();
};

