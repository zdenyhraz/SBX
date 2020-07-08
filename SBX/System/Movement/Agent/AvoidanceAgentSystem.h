#pragma once
#include "System/SubSystem.h"

class AvoidanceAgentSystem : public SubSystem
{
public:

	AvoidanceAgentSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

	int FindClosestEntity( int agentId );

private:

};
