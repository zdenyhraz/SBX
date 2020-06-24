#include "AvoidanceAgentSystem.h"

AvoidanceAgentSystem::AvoidanceAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	m_Components( components ),
	m_Managers( managers )
{

}

void AvoidanceAgentSystem::Tick()
{
	for ( auto &agent : m_Components->AvoidanceAgents.Data )
	{
		int agentId = agent.first;
		PositionComponent &agentPos = m_Components->Positions.Find( agentId );

		int closestId = FindClosestEntity( agentId );
		PositionComponent &closestPos = m_Components->Positions.Find( closestId );

		cv::Point2d fleeDirection = agentPos.Position - closestPos.Position;
		m_Components->Velocities.Find( agentId ).Velocity = fleeDirection / cv::norm( fleeDirection ) * agent.second.FleeSpeed;
	}
}

int AvoidanceAgentSystem::FindClosestEntity( int agentId )
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