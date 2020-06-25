#include "SwarmAgentSystem.h"

SwarmAgentSystem::SwarmAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	m_Components( components ),
	m_Managers( managers ),
	m_BoundaryW( 3.0 ),
	m_AlignmentW( 1.0 ),
	m_SeparationW( 1.0 ),
	m_CohesionW( 1.0 ),
	m_VisionRadius( 0.1 ),
	m_Speed( 3.8 ),
	m_Acceleration( 1.0 )
{
	m_Accelerations.reserve( 1000 );
}

void SwarmAgentSystem::Tick()
{
	m_Accelerations.clear();
	for ( auto &agent : m_Components->SwarmAgents.Data )
	{
		int agentId = agent.first;
		cv::Point2d separation = GetSeparationDirection( agentId );
		cv::Point2d alignment = GetAlignmentDirection( agentId );
		cv::Point2d cohesion = GetCohesionDirection( agentId );
		cv::Point2d boundary = GetBoundaryDirection( agentId );
		cv::Point2d agentVelocity = m_Components->Velocities.Find( agentId ).Velocity;
		cv::Point2d swarmVelocity = m_Speed * ( separation * m_SeparationW + alignment * m_AlignmentW + cohesion * m_CohesionW + boundary * m_BoundaryW ) / ( m_SeparationW + m_AlignmentW + m_CohesionW + m_BoundaryW );
		cv::Point2d acceleration = m_Acceleration * ( swarmVelocity - agentVelocity );

		m_Accelerations.emplace( std::make_pair( agentId, acceleration ) );
	}

	for ( auto &agent : m_Components->SwarmAgents.Data )
	{
		m_Components->Accelerations.Find( agent.first ).Acceleration = m_Accelerations.find( agent.first )->second;
	}
}

cv::Point2d SwarmAgentSystem::GetSeparationDirection( int id )
{
	cv::Point2d separation( 0, 0 );
	PositionComponent &mainAgentPos = m_Components->Positions.Find( id );

	for ( auto &agent : m_Components->SwarmAgents.Data )
	{
		if ( agent.first == id )
		{
			continue;
		}

		PositionComponent &agentPos = m_Components->Positions.Find( agent.first );
		cv::Point2d direction = mainAgentPos.Position - agentPos.Position;
		double distance = cv::norm( direction );

		if ( distance < m_VisionRadius )
		{
			separation += Utils::UnitVector( direction ) / std::max( distance, 1e-6 );
		}
	}
	return Utils::UnitVector( separation );
}

cv::Point2d SwarmAgentSystem::GetAlignmentDirection( int id )
{
	cv::Point2d alignment( 0, 0 );
	PositionComponent &mainAgentPos = m_Components->Positions.Find( id );

	for ( auto &agent : m_Components->SwarmAgents.Data )
	{
		if ( agent.first == id )
		{
			continue;
		}

		PositionComponent &agentPos = m_Components->Positions.Find( agent.first );
		cv::Point2d direction = mainAgentPos.Position - agentPos.Position;
		double distance = cv::norm( direction );

		if ( distance < m_VisionRadius )
		{
			VelocityComponent &agentVel = m_Components->Velocities.Find( agent.first );

			alignment += Utils::UnitVector( agentVel.Velocity );
		}
	}
	return Utils::UnitVector( alignment );
}

cv::Point2d SwarmAgentSystem::GetCohesionDirection( int id )
{
	cv::Point2d center( 0, 0 );
	PositionComponent &mainAgentPos = m_Components->Positions.Find( id );
	int otherAgentsCnt = 0;

	for ( auto &agent : m_Components->SwarmAgents.Data )
	{
		if ( agent.first == id )
		{
			continue;
		}

		PositionComponent &agentPos = m_Components->Positions.Find( agent.first );
		cv::Point2d direction = mainAgentPos.Position - agentPos.Position;
		double distance = cv::norm( direction );

		if ( distance < m_VisionRadius )
		{
			center += agentPos.Position;
			otherAgentsCnt++;
		}
	}
	if ( otherAgentsCnt )
	{
		center /= otherAgentsCnt;
	}
	return Utils::UnitVector( center - mainAgentPos.Position );
}

cv::Point2d SwarmAgentSystem::GetBoundaryDirection( int id )
{
	cv::Point2d boundary( 0, 0 );
	PositionComponent &mainAgentPos = m_Components->Positions.Find( id );

	if ( mainAgentPos.Position.x + m_VisionRadius > m_Components->Map.MaxPositionX )
	{
		return cv::Point2d( -1, 0 );
	}
	if ( mainAgentPos.Position.x - m_VisionRadius < m_Components->Map.MinPositionX )
	{
		return cv::Point2d( 1, 0 );
	}
	if ( mainAgentPos.Position.y + m_VisionRadius > m_Components->Map.MaxPositionY )
	{
		return cv::Point2d( 0, -1 );
	}
	if ( mainAgentPos.Position.y - m_VisionRadius < m_Components->Map.MinPositionY )
	{
		return cv::Point2d( 0, 1 );
	}

	return cv::Point2d( 0, 0 );
}