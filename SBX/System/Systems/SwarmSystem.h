#pragma once
#include "System/System.h"

class SwarmSystem : public System
{
public:

	SwarmSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick( float dt ) override;

private:
	glm::vec3 GetSeparationDirection( int id );
	glm::vec3 GetAlignmentDirection( int id );
	glm::vec3 GetCohesionDirection( int id );
	glm::vec3 GetBoundaryDirection( int id );

	float m_SeparationW;
	float m_AlignmentW;
	float m_CohesionW;
	float m_BoundaryW;
	float m_VisionRadius;
	float m_Speed;
	float m_Acceleration;
};
