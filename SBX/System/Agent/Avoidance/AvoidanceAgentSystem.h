#pragma once
#include "System/Agent/AgentSubSystem.h"

class AvoidanceAgentSystem : public AgentSubSystem
{
public:

	AvoidanceAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

	int FindClosestEntity( int agentId );

private:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
};
