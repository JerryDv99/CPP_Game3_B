#pragma once
#include "Headers.h"

class CollisionManager
{
public:
	static bool RectCollision(Transform _Current, Transform _Target)
	{
		Vector3 CurrentStartPoint = _Current.Position - _Current.Scale / 2;
		Vector3 TargetStartPoint = _Target.Position - _Target.Scale / 2;

		Vector3 CurrentEndPoint = _Current.Position + _Current.Scale / 2;
		Vector3 TargetEndPoint = _Target.Position + _Target.Scale / 2;

		if (CurrentStartPoint.x < TargetEndPoint.x &&
			TargetStartPoint.x < CurrentEndPoint.x &&
			(int)CurrentStartPoint.y <= (int)_Target.Position.y &&
			(int)CurrentEndPoint.y >= (int)_Target.Position.y)
			return true;

		return false;
	}
};