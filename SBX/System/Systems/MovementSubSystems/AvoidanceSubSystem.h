#pragma once
#include "System/SubSystem.h"

class AvoidanceSubSystem : public SubSystem
{
public:

	AvoidanceSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

	int FindClosestEntity( int agentId );

private:

};
