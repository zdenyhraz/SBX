#pragma once
#include "Component/Component.h"

struct SeekingAgentComponent : Component
{
	SeekingAgentComponent( int targetId ):
		TargetId( targetId )
	{
	}

	int TargetId;
};