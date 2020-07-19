#include "LogicSystem.h"

LogicSystem::LogicSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers )
{

}

void LogicSystem::Tick( float dt )
{

}