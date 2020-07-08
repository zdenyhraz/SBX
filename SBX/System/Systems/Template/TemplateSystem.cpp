#include "TemplateSystem.h"

TemplateSystem::TemplateSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Health" )
{

}

void TemplateSystem::Tick()
{

}