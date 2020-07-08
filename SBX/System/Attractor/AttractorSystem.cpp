#include "AttractorSystem.h"

AttractorSystem::AttractorSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Attractor" )
{

}

void AttractorSystem::Tick()
{
	for ( auto &accel : m_Components->Accelerations.GetContainer() )
	{
		constexpr double gravity = 1.0;//5
		accel.second.Acceleration += gravity * Utils::UnitVector( -m_Components->Positions.Find( accel.first ).Position );

	}
}