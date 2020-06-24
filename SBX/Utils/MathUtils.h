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

inline void Clamp( double &val, double minval, double maxval )
{
	val = std::max( std::min( val, maxval ), minval );
}

}
