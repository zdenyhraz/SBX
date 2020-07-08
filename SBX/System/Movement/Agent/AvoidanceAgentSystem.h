#pragma once
#include "System/SubSystem.h"

class AvoidanceAgentSystem : public SubSystem
{
public:

	AvoidanceAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

	int FindClosestEntity( int agentId );

private:

};
