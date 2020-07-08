#pragma once
#include "Stdafx.h"

namespace Utils {

inline long long GetDuration( const std::chrono::time_point<std::chrono::steady_clock> &Start, const std::chrono::time_point<std::chrono::steady_clock> &End )
{
	auto start = std::chrono::time_point_cast<std::chrono::milliseconds>( Start ).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::milliseconds>( End ).time_since_epoch().count();
	return end - start;
}

inline std::chrono::time_point<std::chrono::steady_clock> GetTimeNow()
{
	return std::chrono::steady_clock::now();
}

}


