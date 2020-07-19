#pragma once
#include "Stdafx.h"

namespace Utils {

static constexpr float Pi = 3.1415926535897932384626433f;
static constexpr float TwoPi = Pi * 2;
static constexpr float HalfPi = Pi / 2;
static constexpr float QuartPi = Pi / 4;
static constexpr float E = 2.7182818284590452353602874f;
static constexpr float Rad = 360.0f / 2.0f / Pi;

inline float Rand01()
{
	return ( float )rand() / RAND_MAX;
}

inline float Rand11()
{
	return -1.0f + Rand01() * 2;
}

inline void Clampr( float &val, float minval, float maxval )
{
	val = std::max( std::min( val, maxval ), minval );
}

inline float Clamp( float val, float minval, float maxval )
{
	return std::max( std::min( val, maxval ), minval );
}

inline glm::vec3 UnitVector( const glm::vec3 &pt )
{
	return pt / std::max( glm::length( pt ), 1e-6f );
}

inline float GetAngle( const glm::vec3 &pt1, const glm::vec3 &pt2 )
{
	float a = ( glm::dot( pt1, pt2 ) ) / ( glm::length( pt1 ) * glm::length( pt2 ) );
	return acos( a );
}

inline float ToDegrees( float rad )
{
	return rad * Rad;
}

inline float ToRadians( float deg )
{
	return deg / Rad;
}

}
