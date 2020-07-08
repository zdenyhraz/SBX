#include "RenderSystem.h"

RenderSystem::RenderSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Render" )
{

}

void RenderSystem::Tick()
{

}