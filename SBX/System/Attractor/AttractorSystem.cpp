#include "AttractorSystem.h"

AttractorSystem::AttractorSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Attractor" )
{

}

void AttractorSystem::Tick()
{
	for ( auto &accel : m_Components->Accelerations.Data )
	{
		constexpr double gravity = 5.0;
		accel.second.Acceleration += gravity * -m_Components->Positions.Find( accel.first ).Position;
	}
}