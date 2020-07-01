#pragma once
#include "Stdafx.h"

namespace Utils {

inline std::string ThisThreadId()
{
	std::stringstream ss;
	ss << std::this_thread::get_id();
	return ss.str();
}

inline void WaitUntil( const std::chrono::time_point<std::chrono::high_resolution_clock> &time )
{
	while ( true )
	{
		if ( Utils::GetTimeNow() >= time )
		{
			break;
		}
	}
}

}
