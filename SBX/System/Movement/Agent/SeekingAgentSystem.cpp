#include "SeekingAgentSystem.h"
#include "Utils/MathUtils.h"

SeekingAgentSystem::SeekingAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	SubSystem( components, managers )
{

}

void SeekingAgentSystem::Tick()
{
	for ( auto &agent : m_Components->Agents.GetContainer() )
	{
		int agentId = agent.first;
		int targetId = agent.second.TargetId;
		auto &agentPos = m_Components->Positions.Find( agentId );
		auto &targetPos = m_Components->Positions.Find( targetId );
		auto seekDirection = targetPos.Position - agentPos.Position;
		m_Components->Velocities.Find( agentId ).Velocity = Utils::UnitVector( seekDirection ) * agent.second.SeekSpeed;
	}
}
