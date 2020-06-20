#pragma once
#include "Stdafx.h"
#include "System.h"

class DrawSystem : public System
{
public:

	DrawSystem( std::shared_ptr<ComponentVectors> components ): System( components )
	{
		m_WindowName = "SBX";
		m_WindowWidth = 1500;
		m_WindowHeight = 1000;
		m_Blank = cv::Mat::zeros( m_WindowHeight, m_WindowWidth, CV_32FC3 );
		m_Live = cv::Mat::zeros( m_WindowHeight, m_WindowWidth, CV_32FC3 );
		m_DrawEntityRadius = 20;
		m_DrawEntityColor = cv::Scalar( 0, 0, 1 );
		m_DrawEntityThickness = 5;
	}

	void Tick( double dt ) override
	{
		m_Live = m_Blank.clone();

		for ( auto &entity : m_Components->EntityInfos.Data )
		{
			if ( entity.second.m_Drawable )
			{
				m_Live.at<cv::Vec3f>( 0, 0 )[2] = 1;
				//cv::circle( m_Live, cv::Point( 0, 0 ), m_DrawEntityRadius, m_DrawEntityColor, m_DrawEntityThickness );
			}
		}

		cv::namedWindow( m_WindowName, cv::WINDOW_NORMAL );
		cv::resizeWindow( m_WindowName, m_WindowWidth, m_WindowHeight );
		cv::imshow( m_WindowName, m_Live );
		cv::waitKey( 1 );
	}

private:
	std::string m_WindowName;
	int m_WindowWidth;
	int m_WindowHeight;
	cv::Mat m_Blank;
	cv::Mat m_Live;
	int m_DrawEntityRadius;
	cv::Scalar m_DrawEntityColor;
	int m_DrawEntityThickness;

};
