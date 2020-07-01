#pragma once
#include "Component/Component.h"

struct AccelerationComponent : Component
{
	cv::Point2d Acceleration;

	void Clear()
	{
		Acceleration = cv::Point2d( 0, 0 );
	}

};