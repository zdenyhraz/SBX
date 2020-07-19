#pragma once

struct TimeComponent
{
	static constexpr int RefreshRate = 75;
	static constexpr long long TargetTickDuration = ( long long )( 1. / RefreshRate * 1000 );
	float Time = 0.0f;
	float Delta = 1.0f / RefreshRate;
	float TimeRate = 1.0f;
	bool Running = true;
	long long TickId = 0;
	std::chrono::time_point<std::chrono::steady_clock> TargetTickEnd = std::chrono::steady_clock::now();
};