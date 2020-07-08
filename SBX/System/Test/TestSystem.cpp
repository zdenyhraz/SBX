#include "TestSystem.h"

TestSystem::TestSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Test" )
{

}

void TestSystem::Tick()
{

}