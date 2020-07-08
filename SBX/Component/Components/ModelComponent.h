#pragma once
#include "Component/Component.h"

struct ModelComponent : Component
{
	ModelComponent():
		Color( 1, 1, 1 ),
		Size( 5 )
	{

	}

	cv::Scalar Color;
	int Size;
};