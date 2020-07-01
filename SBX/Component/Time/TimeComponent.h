#pragma once
#include "Component/Component.h"

struct TimeComponent : Component
{
	static constexpr int RefreshRate = 75;

	TimeComponent() :
		Time( 0 ),
		TimeRate( 1 ),
		Delta( 1. / RefreshRate ),
		Running( true )
	{

	}

	double Time;
	double Delta;
	double TimeRate;
	bool Running;
};