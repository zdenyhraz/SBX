#pragma once
#include "Stdafx.h"

namespace Utils {

inline long long GetDuration( const std::chrono::time_point<std::chrono::high_resolution_clock> &Start, const std::chrono::time_point<std::chrono::high_resolution_clock> &End )
{
	auto start = std::chrono::time_point_cast<std::chrono::microseconds>( Start ).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>( End ).time_since_epoch().count();
	return end - start;
}

inline std::chrono::time_point<std::chrono::high_resolution_clock> GetTimeNow()
{
	return std::chrono::high_resolution_clock::now();
}

}


