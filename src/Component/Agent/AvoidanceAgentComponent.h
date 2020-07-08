#pragma once
#include "Component/Component.h"

struct AvoidanceAgentComponent : Component
{
	AvoidanceAgentComponent():
		FleeSpeed( 0.1 )
	{
	}

	double FleeSpeed;
};