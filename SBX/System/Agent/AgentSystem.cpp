#include "AgentSystem.h"

AgentSystem::AgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Agent", 100, true )
{

}

void AgentSystem::Tick()
{
	for ( auto &agent : m_Components->Agents.Data )
	{
		int id = agent.first;


	}
}