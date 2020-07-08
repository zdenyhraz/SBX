#include "AttractorSubSystem.h"

AttractorSubSystem::AttractorSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	SubSystem( components, managers )
{

}

void AttractorSubSystem::Tick()
{
	for ( auto &accel : m_Components->Accelerations.GetContainer() )
	{
		constexpr double gravity = 3.0;
		accel.second.Acceleration += gravity * Utils::UnitVector( -m_Components->Positions.Find( accel.first ).Position );
	}
}