#pragma once
#include "Stdafx.h"
#include "Component.h"

class ModelComponent : public Component
{
public:

	ModelComponent():
		Color( 1, 1, 1 ),
		Size( 5 )
	{

	}

	cv::Scalar Color;
	int Size;

private:
};