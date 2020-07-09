#pragma once
#include "Component/Component.h"

struct ModelComponent : Component
{
	cv::Scalar Color = cv::Scalar( 1, 1, 1 );
	int Size = 5;
};