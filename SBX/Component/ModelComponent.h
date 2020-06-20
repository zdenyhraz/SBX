#pragma once
#include "Stdafx.h"
#include "Component.h"

class ModelComponent : public Component
{
public:

	ModelComponent( cv::Scalar &&color = cv::Scalar( 0.0, 0.8, 0.0 ), int size = 5 ):
		m_Color( std::move( color ) ),
		m_Size( size )
	{

	}

	cv::Scalar m_Color;
	int m_Size;

private:
};