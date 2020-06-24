#pragma once
#include "Component/Component.h"

struct SeekingAgentComponent : Component
{
	SeekingAgentComponent( int targetId ):
		TargetId( targetId ),
		SeekSpeed( 0.1 )
	{
	}

	int TargetId;
	double SeekSpeed;

};