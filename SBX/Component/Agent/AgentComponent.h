#pragma once
#include "Component/Component.h"

struct AgentComponent : Component
{
	AgentComponent():
		Avoiding( false ),
		Seeking( false ),
		Swarming( false )
	{

	}

	bool Avoiding;
	bool Seeking;
	bool Swarming;

	double AvoidSpeed;
	double SeekSpeed;
	int TargetId;
};