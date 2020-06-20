#pragma once
#include "Stdafx.h"
#include "Component.h"

class ModelComponent : public Component
{
public:

	ModelComponent( cv::Scalar &&color = cv::Scalar( 0.0, 0.8, 0.0 ) ): m_Color( std::move( color ) )
	{

	}

	cv::Scalar m_Color;
private:
};