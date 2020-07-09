#pragma once
#include "Component/Component.h"

struct VelocityComponent : Component
{
	cv::Point2d Velocity = cv::Point2d( 0, 0 );
};