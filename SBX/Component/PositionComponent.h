#pragma once
#include "Stdafx.h"
#include "Component.h"

class PositionComponent : public Component
{
public:
	cv::Point2d Position;
private:
};