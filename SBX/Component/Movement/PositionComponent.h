#pragma once
#include "Stdafx.h"
#include "Component/Component.h"

class PositionComponent : public Component
{
public:
	cv::Point2d Position;
private:
};