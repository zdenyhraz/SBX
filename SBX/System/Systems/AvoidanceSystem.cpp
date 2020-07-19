#include "AvoidanceSystem.h"
#include "Utils/MathUtils.h"

AvoidanceSystem::AvoidanceSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers )
{

}

void AvoidanceSystem::Tick( float dt )
{
	for ( auto &agent : m_Components->Agents.GetContainer() )
	{
		if ( agent.second.MovementBehaviour != AgentComponent::Avoiding )
		{
			continue;
		}

		int agentId = agent.first;
		PositionComponent &agentPos = m_Components->Positions.Find( agentId );

		int closestId = FindClosestEntity( agentId );
		PositionComponent &closestPos = m_Components->Positions.Find( closestId );

		glm::vec3 fleeDirection = agentPos.Position - closestPos.Position;
		m_Components->Velocities.Find( agentId ).Velocity = Utils::UnitVector( fleeDirection ) * agent.second.AvoidSpeed;
	}
}

int AvoidanceSystem::FindClosestEntity( int agentId )
{
	PositionComponent &agentPos = m_Components->Positions.Find( agentId );
	int closestId;
	double closestDistance = std::numeric_limits<double>::max();
	for ( auto &agent : m_Components->Agents.GetContainer() )
	{
		if ( agent.first == agentId )
		{
			continue;
		}

		auto &pos = m_Components->Positions.Find( agent.first );
		double distance = glm::length( agentPos.Position - pos.Position );
		if ( distance < closestDistance )
		{
			closestDistance = distance;
			closestId = agent.first;
		}
	}
	return closestId;
}