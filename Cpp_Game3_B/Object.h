#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
	Object* Target;
	string Key;
	float Speed;
	float Weight;
	int Index;
	int  HP;
public:
	virtual Object* Start(string _Key)PURE;
	virtual int   Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;
public:
	Transform GetTransform() const { return Info; }
	string GetKey() const { return Key; }
	void SetKey(const string& _Key) { Key = _Key; }

	Vector3 GetPosition() const { return Info.Position; }
	Vector3 GetDirection() const { return Info.Direction; }
	void SetPosition(Vector3 _Position) { Info.Position = _Position; }
	void SetPosition(float _x, float _y) { Info.Position = Vector3(_x, _y); }

	void SetScale(float _x, float _y) { Info.Scale = Vector3(_x, _y); }

	void SetDirection(Vector3 _Direction) { Info.Direction = _Direction; }
	void SetDirection(float _x, float _y) { Info.Direction = Vector3(_x, _y); }
	void SetTarget(Object* _Target) { Target = _Target; }

	void SetWeight(float _Weight) { Weight = _Weight; }
	int GetHP() { return HP; }
	void SetHP(int _HP) { HP = _HP; }
	void ReduceHP(int _HP) { HP -= _HP; }

	int GetIndex() { return Index; }
	float GetSpeed() { return Speed; }
	void SetIndex(int _Index) { Index = _Index; }

	float GetStartPos() const { return Info.Position.x -  Info.Scale.x / 2; }
	float GetEndPos() const { return Info.Position.x +  Info.Scale.x / 2; }
public:
	Object();
	Object(Transform _Info) : Info(_Info), Speed(0.0f), Target(nullptr) {};
	virtual ~Object();
};