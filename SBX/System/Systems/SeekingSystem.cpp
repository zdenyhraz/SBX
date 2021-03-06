#include "SeekingSystem.h"
#include "Utils/MathUtils.h"

SeekingSystem::SeekingSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers )
{

}

void SeekingSystem::Tick(float dt)
{
	for ( auto &agent : m_Components->Agents.GetContainer() )
	{
		if ( agent.second.MovementBehaviour != AgentComponent::Seeking )
		{
			continue;
		}

		int agentId = agent.first;
		int targetId = agent.second.TargetId;
		auto &agentPos = m_Components->Positions.Find( agentId );
		auto &targetPos = m_Components->Positions.Find( targetId );
		auto seekDirection = targetPos.Position - agentPos.Position;
		m_Components->Velocities.Find( agentId ).Velocity = Utils::UnitVector( seekDirection ) * agent.second.SeekSpeed;
	}
}
