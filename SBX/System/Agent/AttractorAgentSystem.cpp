#include "AttractorAgentSystem.h"

AttractorAgentSystem::AttractorAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	AgentSubSystem( components, managers )
{

}

void AttractorAgentSystem::Tick()
{
	for ( auto &accel : m_Components->Accelerations.GetContainer() )
	{
		constexpr double gravity = 3.0;
		accel.second.Acceleration += gravity * Utils::UnitVector( -m_Components->Positions.Find( accel.first ).Position );
	}
}