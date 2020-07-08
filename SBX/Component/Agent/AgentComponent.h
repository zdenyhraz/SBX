#pragma once
#include "Component/Component.h"

struct AgentComponent : Component
{
	AgentComponent():
		Fleeing( false ),
		Seeking( false ),
		Swarming( false )
	{

	}

	bool Fleeing;
	bool Seeking;
	bool Swarming;

	double FleeSpeed;
	double SeekSpeed;
	int TargetId;
};