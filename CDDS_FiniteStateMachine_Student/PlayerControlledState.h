#pragma once
#include "State.h"
#include "GameObject.h"



class PlayerControlledState : public State
{
public:
	PlayerControlledState()
	{
		;
	}
	~PlayerControlledState()
	{
		;
	}

	void onUpdate(GameObject* object, float deltaTime);
};