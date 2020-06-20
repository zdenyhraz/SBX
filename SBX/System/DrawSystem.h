#pragma once
#include "Stdafx.h"
#include "System.h"

class DrawSystem : public System
{
public:

	DrawSystem( std::shared_ptr<ComponentVectors> components ): System( components, "draw" )
	{
		m_WindowName = "SBX";
		m_WindowWidth = 1200;
		m_WindowHeight = 1200;
		m_WindowCenter = cv::Point( m_WindowWidth / 2, m_WindowHeight / 2 );
		m_MapWidth = 1.0;
		m_MapHeight = 1.0;
		m_Blank = cv::Mat::zeros( m_WindowHeight, m_WindowWidth, CV_32FC3 );
		m_Live = m_Blank.clone();
		m_DrawEntityRadius = 7;
		m_DrawEntityThickness = -1;
	}

	void Tick( double dt ) override
	{
		m_Live = m_Blank.clone();

		for ( auto &entity : m_Components->EntityInfos.Data )
		{
			if ( entity.second.m_Drawable )
			{
				auto pos = m_Components->Positions.Find( entity.first );
				cv::circle( m_Live, GetWindowCoordinates( pos.x, pos.y ), m_DrawEntityRadius, cv::Scalar( 0.8, 0.3, 0.1 ), m_DrawEntityThickness );
			}
		}

		cv::namedWindow( m_WindowName, cv::WINDOW_NORMAL );
		cv::resizeWindow( m_WindowName, m_WindowWidth, m_WindowHeight );
		cv::imshow( m_WindowName, m_Live );
		cv::waitKey( 1 );
	}

	cv::Point GetWindowCoordinates( double x, double y )
	{
		return m_WindowCenter + cv::Point( ( int )( ( x / m_MapWidth ) * ( m_WindowWidth / 2 ) ), ( int )( ( y / m_MapHeight ) * ( m_WindowHeight / 2 ) ) );
	}

private:
	std::string m_WindowName;
	int m_WindowWidth;
	int m_WindowHeight;
	cv::Point m_WindowCenter;
	double m_MapWidth;
	double m_MapHeight;
	cv::Mat m_Blank;
	cv::Mat m_Live;
	int m_DrawEntityRadius;
	int m_DrawEntityThickness;
};
