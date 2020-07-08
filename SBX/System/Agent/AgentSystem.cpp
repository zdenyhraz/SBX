#include "AgentSystem.h"
#include "AvoidanceAgentSystem.h"
#include "SeekingAgentSystem.h"
#include "SwarmAgentSystem.h"
#include "NomNomAgentSystem.h"
#include "AttractorAgentSystem.h"

AgentSystem::AgentSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Agent" )
{
	//m_AgentSubSystems.push_back( std::make_shared<AvoidanceAgentSystem>( components, managers ) );
	//m_AgentSubSystems.push_back( std::make_shared<SeekingAgentSystem>( components, managers ) );
	//m_AgentSubSystems.push_back( std::make_shared<NomNomAgentSystem>( components, managers ) );
	m_AgentSubSystems.push_back( std::make_shared<SwarmAgentSystem>( components, managers ) );
	m_AgentSubSystems.push_back( std::make_shared<AttractorAgentSystem>( components, managers ) );
}

void AgentSystem::Tick()
{
	for ( auto &system : m_AgentSubSystems )
	{
		system->Tick();
	}
}