#pragma once

struct TimeComponent
{
	static constexpr int RefreshRate = 75;
	static constexpr long long TargetTickDuration = ( long long )( 1. / RefreshRate * 1000 );
	double Time = 0;
	double Delta = 1. / RefreshRate;
	double TimeRate = 1;
	bool Running = true;
	long long TickId = 0;
	std::chrono::time_point<std::chrono::steady_clock> TargetTickEnd = std::chrono::steady_clock::now();
};