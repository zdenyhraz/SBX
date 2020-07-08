#include "LogicSystem.h"
#include "HealthSubSystem.h"

LogicSystem::LogicSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Logic" )
{
	m_SubSystems.push_back( std::make_shared<HealthSubSystem>( components, managers ) );
}

void LogicSystem::Tick()
{
	for ( auto &subsystem : m_SubSystems )
	{
		subsystem->Tick();
	}
}