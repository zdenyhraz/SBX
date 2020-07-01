#pragma once
#include "Component/Component.h"

struct TimeComponent : Component
{
	enum RefreshRate
	{
		Normal = 60,
		Double = 2 * Normal,
		Max = -1
	};

	TimeComponent() :
		Time( 0 ),
		TimeRate( 1 ),
		Delta( 1. / RefreshRate::Normal ),
		Running( true )
	{

	}

	double Time;
	double Delta;
	double TimeRate;
	bool Running;
};