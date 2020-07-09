#include "TemplateSubSystem.h"

TemplateSubSystem::TemplateSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	SubSystem( components, managers )
{

}

void TemplateSubSystem::Tick()
{

}