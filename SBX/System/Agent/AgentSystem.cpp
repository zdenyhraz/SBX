#include "AgentSystem.h"

AgentSystem::AgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Agent", 60, true )
{
	m_AvoidanceAgentSystem = std::make_shared<AvoidanceAgentSystem>( components, managers );
	m_SeekingAgentSystem = std::make_shared<SeekingAgentSystem>( components, managers );
	m_SwarmAgentSystem = std::make_shared<SwarmAgentSystem>( components, managers );
}

void AgentSystem::Tick()
{
	m_AvoidanceAgentSystem->Tick();
	m_SeekingAgentSystem->Tick();
	m_SwarmAgentSystem->Tick();
}