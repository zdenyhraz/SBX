#pragma once
#include "Stdafx.h"

namespace Utils {

static constexpr double Pi = 3.1415926535897932384626433;
static constexpr double TwoPi = Pi * 2;
static constexpr double HalfPi = Pi / 2;
static constexpr double QuartPi = Pi / 4;
static constexpr double E = 2.7182818284590452353602874;
static constexpr double Rad = 360. / 2. / Pi;

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

inline double GetAngle( const cv::Point2d &pt1, const cv::Point2d &pt2 )
{
	double a = ( pt1.dot( pt2 ) ) / ( cv::norm( pt1 ) * cv::norm( pt2 ) );
	return acos( a );
}

inline double ToDegrees( double rad )
{
	if ( rad < 0 )
	{
		return ( rad + TwoPi ) * Rad;
	}
	else
	{
		return rad * Rad;
	}
}

inline double ToRadians( double deg )
{
	return deg / Rad;
}

}
