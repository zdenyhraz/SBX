#include "AttractorAgentSystem.h"

AttractorAgentSystem::AttractorAgentSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	AgentSubSystem( components, managers )
{

}

void AttractorAgentSystem::Tick()
{
	for ( auto &accel : m_Components->Past.Accelerations.GetContainer() )
	{
		constexpr double gravity = 3.0;
		accel.second.Acceleration += gravity * Utils::UnitVector( -m_Components->Past.Positions.Find( accel.first ).Position );
	}
}