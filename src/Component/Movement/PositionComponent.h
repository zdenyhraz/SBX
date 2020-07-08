#pragma once
#include "Component/Component.h"

struct PositionComponent : Component
{
	cv::Point2d Position;
};