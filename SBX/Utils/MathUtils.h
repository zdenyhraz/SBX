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

inline cv::Point2d UnitVector( const cv::Point2d &pt )
{
	return pt / std::max( cv::norm( pt ), 1e-6 );
}

}
