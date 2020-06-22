#pragma once
#include "Stdafx.h"

namespace Utils {

inline std::string ThisThreadId()
{
	std::stringstream ss;
	ss << std::this_thread::get_id();
	return ss.str();
}

}
