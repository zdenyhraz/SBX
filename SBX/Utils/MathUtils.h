#pragma once
#include "Stdafx.h"

namespace Utils {

inline double Rand01()
{
	return ( double )rand() / RAND_MAX;
}

inline double Rand11()
{
	return -1. + Rand01() * 2;
}

}
