#pragma once
#include "Headers.h"

class Object;
class ObjectpoolManager
{
private:
	static ObjectpoolManager* Instance;
public:
	static ObjectpoolManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectpoolManager;
		return Instance;
	}
private:
	map<string, list<Object*>> EnableList;

	map<string, list<Object*>> DisableList;
public:
	bool FindObject(string _Key);
	void AddObject(string _Key);
	void SwitchingObject(string _Key, Vector3 _Position = Vector3());
	Object* GetObj(string _Key);
	Object* SearchObj(string _Key);
	void PutEnable(string _Key, Object* _Obj);
	void Update();
	void Render();
	list<Object*> GetList(string _Key);
private:
	ObjectpoolManager();
public:
	~ObjectpoolManager();
};

