#pragma once
#include "Stdafx.h"

static std::string ThisThreadId()
{
	std::stringstream ss;
	ss << std::this_thread::get_id();
	return ss.str();
}