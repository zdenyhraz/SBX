#include "AgentSystem.h"

AgentSystem::AgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Agent", 120, true )
{
	m_AvoidanceAgentSystem = std::make_shared<AvoidanceAgentSystem>( components, managers );
	m_SeekingAgentSystem = std::make_shared<SeekingAgentSystem>( components, managers );
}

void AgentSystem::Tick()
{
	m_AvoidanceAgentSystem->Tick();
	m_SeekingAgentSystem->Tick();

}