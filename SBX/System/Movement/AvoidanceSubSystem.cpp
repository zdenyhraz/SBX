#include "AvoidanceSubSystem.h"
#include "Utils/MathUtils.h"

AvoidanceSubSystem::AvoidanceSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	SubSystem( components, managers )
{

}

void AvoidanceSubSystem::Tick()
{
	for ( auto &agent : m_Components->Agents.GetContainer() )
	{
		if ( !agent.second.Avoiding )
		{
			continue;
		}

		int agentId = agent.first;
		PositionComponent &agentPos = m_Components->Positions.Find( agentId );

		int closestId = FindClosestEntity( agentId );
		PositionComponent &closestPos = m_Components->Positions.Find( closestId );

		cv::Point2d fleeDirection = agentPos.Position - closestPos.Position;
		m_Components->Velocities.Find( agentId ).Velocity = Utils::UnitVector( fleeDirection ) * agent.second.AvoidSpeed;
	}
}

int AvoidanceSubSystem::FindClosestEntity( int agentId )
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
		double distance = cv::norm( agentPos.Position - pos.Position );
		if ( distance < closestDistance )
		{
			closestDistance = distance;
			closestId = agent.first;
		}
	}
	return closestId;
}