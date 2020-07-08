#include "RenderSystem.h"

RenderSystem::RenderSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Template" )
{

}

void RenderSystem::Tick()
{

}