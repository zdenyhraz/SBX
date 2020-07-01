#pragma once
#include "System/System.h"

class DrawSystem : public System
{
public:

	DrawSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

	cv::Point GetWindowCoordinates( double x, double y );

private:
	std::string m_WindowName;
	int m_WindowWidth;
	int m_WindowHeight;
	cv::Point m_WindowCenter;
	cv::Mat m_Blank;
	cv::Mat m_Live;
	int m_DrawEntityThickness;
	double m_TextRelOffsetX;
	double m_TextRelOffsetY;
	double m_TextRelScale;
	double m_TextMinRelScale;
	int m_TextThickness;
	double m_DrawEntityArrowLengthScale;
	double m_DrawEntityArrowThicknessScale;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickStart;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickEnd;
	long long m_TickDuration;
	int m_FpsTextThickness;
	cv::Scalar m_FpsTextColor;
	double m_FpsTextScale;
};
