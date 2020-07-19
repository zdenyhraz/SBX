#pragma once
#include "System/System.h"

class AvoidanceSystem : public System
{
public:

	AvoidanceSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick( float dt ) override;

private:
	int FindClosestEntity( int agentId );
};
