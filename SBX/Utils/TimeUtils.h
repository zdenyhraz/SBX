#pragma once
#include "Stdafx.h"

namespace Utils {
long long GetDuration( const std::chrono::time_point<std::chrono::high_resolution_clock> &Start, const std::chrono::time_point<std::chrono::high_resolution_clock> &End )
{
	long long start = std::chrono::time_point_cast<std::chrono::microseconds>( Start ).time_since_epoch().count();
	long long end = std::chrono::time_point_cast<std::chrono::microseconds>( End ).time_since_epoch().count();
	return end - start;
}

std::chrono::time_point<std::chrono::high_resolution_clock> GetCurrentTime()
{
	return std::chrono::high_resolution_clock::now();
}
}


