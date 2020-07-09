#include "LogicSystem.h"
#include "LogicSubSystems/HealthSubSystem.h"
#include "LogicSubSystems/EventSubSystem.h"

LogicSystem::LogicSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Logic" )
{
	m_SubSystems.push_back( std::make_shared<HealthSubSystem>( components, managers ) );
	m_SubSystems.push_back( std::make_shared<EventSubSystem>( components, managers ) );
}

void LogicSystem::Tick()
{
	for ( auto &subsystem : m_SubSystems )
	{
		subsystem->Tick();
	}
}