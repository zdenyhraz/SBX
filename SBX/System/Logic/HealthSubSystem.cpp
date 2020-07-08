#include "HealthSubSystem.h"

HealthSubSystem::HealthSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	SubSystem( components, managers )
{

}

void HealthSubSystem::Tick()
{

}