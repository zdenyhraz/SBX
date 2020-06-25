#pragma once
#include "System/System.h"

class SwarmAgentSystem
{
public:

	SwarmAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick();

private:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;

	cv::Point2d GetSeparationDirection( int id );

	cv::Point2d GetAlignmentDirection( int id );

	cv::Point2d GetCohesionDirection( int id );

	cv::Point2d GetBoundaryDirection( int id );

	double m_SeparationW;
	double m_AlignmentW;
	double m_CohesionW;
	double m_BoundaryW;
	double m_VisionRadius;
	double m_Speed;
	double m_Acceleration;
	std::unordered_map<int, cv::Point2d> m_Accelerations;
};
