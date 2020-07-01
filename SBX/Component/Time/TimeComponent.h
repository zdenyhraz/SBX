#pragma once
#include "Component/Component.h"

struct TimeComponent : Component
{
	static constexpr int RefreshRate = 75;
	static constexpr long long TargetTickDuration = ( long long )( 1. / RefreshRate * 1000 );

	TimeComponent() :
		Time( 0 ),
		TimeRate( 1 ),
		Delta( 1. / RefreshRate ),
		Running( true )
	{
		TargetTickEnd = Utils::GetTimeNow();
	}

	double Time;
	double Delta;
	double TimeRate;
	bool Running;
	std::chrono::time_point<std::chrono::steady_clock> TargetTickEnd;
};