#include "LogicSystem.h"

LogicSystem::LogicSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Logic" )
{

}

void LogicSystem::Tick()
{

}