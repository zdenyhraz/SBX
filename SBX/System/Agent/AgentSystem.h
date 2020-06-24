#pragma once
#include "System/System.h"
#include "Avoidance/AvoidanceAgentSystem.h"
#include "Seeking/SeekingAgentSystem.h"
#include "Swarm/SwarmAgentSystem.h"

class AgentSystem : public System
{
public:

	AgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
	std::shared_ptr<AvoidanceAgentSystem> m_AvoidanceAgentSystem;
	std::shared_ptr<SeekingAgentSystem> m_SeekingAgentSystem;
	std::shared_ptr<SwarmAgentSystem> m_SwarmAgentSystem;

};
