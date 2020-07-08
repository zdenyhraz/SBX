#include "TemplateSystem.h"

TemplateSystem::TemplateSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Template" )
{

}

void TemplateSystem::Tick()
{

}