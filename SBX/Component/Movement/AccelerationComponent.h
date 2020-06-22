#pragma once
#include "Stdafx.h"
#include "Component.h"

class AccelerationComponent : public Component
{
public:
	cv::Point2d Acceleration;
private:
};