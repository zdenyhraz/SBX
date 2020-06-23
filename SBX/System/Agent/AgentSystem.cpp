#include "AgentSystem.h"

AgentSystem::AgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Agent", 100, true ),
	m_FleeSpeed( 0.1 )
{

}

void AgentSystem::Tick()
{
	for ( auto &agent : m_Components->Agents.Data )
	{
		int agentId = agent.first;
		PositionComponent &agentPos = m_Components->Positions.Find( agentId );

		int closestId = FindClosestEntity( agentId );
		PositionComponent &closestPos = m_Components->Positions.Find( closestId );

		cv::Point2d fleeDirection = agentPos.Position - closestPos.Position;
		m_Components->Velocities.Find( agentId ).Velocity = fleeDirection / cv::norm( fleeDirection ) * m_FleeSpeed;
	}
}

int AgentSystem::FindClosestEntity( int agentId )
{
	PositionComponent &agentPos = m_Components->Positions.Find( agentId );
	int closestId;
	double closestDistance = std::numeric_limits<double>::max();
	for ( auto &pos : m_Components->Positions.Data )
	{
		if ( pos.first == agentId )
		{
			continue;
		}

		double distance = cv::norm( agentPos.Position - pos.second.Position );
		if ( distance < closestDistance )
		{
			closestDistance = distance;
			closestId = pos.first;
		}
	}
	return closestId;
}