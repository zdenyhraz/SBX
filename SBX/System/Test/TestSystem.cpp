#include "TestSystem.h"

TestSystem::TestSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Test" )
{

}

void TestSystem::Tick()
{

}