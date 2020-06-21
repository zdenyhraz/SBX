#pragma once
#include "Stdafx.h"
#include "System.h"

class DrawSystem : public System
{
public:

	DrawSystem( std::shared_ptr<ComponentVectors> components ):
		System( components, "Draw" )
	{
		m_WindowName = "SBX";
		m_WindowWidth = 1000;
		m_WindowHeight = 1000;
		m_WindowCenter = cv::Point( m_WindowWidth / 2, m_WindowHeight / 2 );
		m_MapWidth = 1;
		m_MapHeight = 1;
		m_Blank = cv::Mat::zeros( m_WindowHeight, m_WindowWidth, CV_32FC3 );
		m_Live = m_Blank.clone();
		m_DrawEntityThickness = -1;
	}

	void Tick() override
	{
		m_Live = m_Blank.clone();

		for ( auto &model : m_Components->Models.Data )
		{
			auto pos = m_Components->Positions.Find( model.first );
			cv::circle( m_Live, GetWindowCoordinates( pos.x, pos.y ), model.second.m_Size, model.second.m_Color, m_DrawEntityThickness );
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
	int m_DrawEntityThickness;
};
