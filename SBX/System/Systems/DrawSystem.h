#pragma once
#include "System/System.h"

class DrawSystem : public System
{
public:

	DrawSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick( float dt ) override;

private:
	cv::Point GetWindowCoordinates( float x, float y );

	std::string m_WindowName;
	int m_WindowWidth;
	int m_WindowHeight;
	cv::Point m_WindowCenter;
	cv::Mat m_Blank;
	cv::Mat m_Live;
	int m_DrawEntityThickness;
	float m_TextRelOffsetX;
	float m_TextRelOffsetY;
	float m_TextRelScale;
	float m_TextMinRelScale;
	int m_TextThickness;
	float m_DrawEntityArrowLengthScale;
	float m_DrawEntityArrowThicknessScale;
	std::chrono::time_point<std::chrono::steady_clock> m_TickStart;
	std::chrono::time_point<std::chrono::steady_clock> m_TickEnd;
	long long m_TickDuration;
	int m_FpsTextThickness;
	cv::Scalar m_FpsTextColor;
	float m_FpsTextScale;
	float m_SizeScale;
};
