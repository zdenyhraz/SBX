#include "TestSystem.h"

TestSystem::TestSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Test/Gravity" )
{

}

void TestSystem::Tick()
{
	for ( auto &accel : m_Components->Accelerations.Data )
	{
		constexpr double gravity = 1.0;
		accel.second.Acceleration = m_Components->Positions.Find( accel.first ).Position * -gravity;
	}
}