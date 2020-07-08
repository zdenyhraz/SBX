#pragma once
#include "System/Agent/AgentSubSystem.h"

class SwarmAgentSystem : public AgentSubSystem
{
public:

	SwarmAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:

	cv::Point2d GetSwarmDirection( int id );

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
};
