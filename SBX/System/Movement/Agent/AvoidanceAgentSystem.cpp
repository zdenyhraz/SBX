#include "AvoidanceAgentSystem.h"
#include "Utils/MathUtils.h"

AvoidanceAgentSystem::AvoidanceAgentSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	SubSystem( components, managers )
{

}

void AvoidanceAgentSystem::Tick()
{
	for ( auto &agent : m_Components->Past->Agents.GetContainer() )
	{
		int agentId = agent.first;
		PositionComponent &agentPos = m_Components->Past->Positions.Find( agentId );

		int closestId = FindClosestEntity( agentId );
		PositionComponent &closestPos = m_Components->Past->Positions.Find( closestId );

		cv::Point2d fleeDirection = agentPos.Position - closestPos.Position;
		m_Components->Past->Velocities.Find( agentId ).Velocity = Utils::UnitVector( fleeDirection ) * agent.second.FleeSpeed;
	}
}

int AvoidanceAgentSystem::FindClosestEntity( int agentId )
{
	PositionComponent &agentPos = m_Components->Past->Positions.Find( agentId );
	int closestId;
	double closestDistance = std::numeric_limits<double>::max();
	for ( auto &agent : m_Components->Past->Agents.GetContainer() )
	{
		if ( agent.first == agentId )
		{
			continue;
		}

		auto &pos = m_Components->Past->Positions.Find( agent.first );
		double distance = cv::norm( agentPos.Position - pos.Position );
		if ( distance < closestDistance )
		{
			closestDistance = distance;
			closestId = agent.first;
		}
	}
	return closestId;
}