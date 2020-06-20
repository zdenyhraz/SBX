#pragma once
#include "Stdafx.h"

long long GetDuration( const std::chrono::time_point<std::chrono::high_resolution_clock> &start, const std::chrono::time_point<std::chrono::high_resolution_clock> &end )
{
	long long s = std::chrono::time_point_cast<std::chrono::microseconds>( start ).time_since_epoch().count();
	long long e = std::chrono::time_point_cast<std::chrono::microseconds>( end ).time_since_epoch().count();
	return e - s;
}