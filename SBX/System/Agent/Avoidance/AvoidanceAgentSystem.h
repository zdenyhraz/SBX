#pragma once
#include "System/System.h"

class AvoidanceAgentSystem
{
public:

	AvoidanceAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick();

	int FindClosestEntity( int agentId );

private:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
};
