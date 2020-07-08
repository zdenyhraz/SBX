#pragma once
#include "System/SubSystem.h"

class SwarmSubSystem : public SubSystem
{
public:

	SwarmSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:

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
