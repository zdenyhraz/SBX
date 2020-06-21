#pragma once
#include "Stdafx.h"
#include "Component.h"

class ModelComponent : public Component
{
public:

	ModelComponent( cv::Scalar &&color = cv::Scalar( 0.0, 0.8, 0.0 ), int size = 5 ):
		Color( std::move( color ) ),
		Size( size )
	{

	}

	cv::Scalar Color;
	int Size;

private:
};