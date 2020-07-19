#include "SwarmSystem.h"

SwarmSystem::SwarmSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers ),
	m_BoundaryW( 3.0f ),
	m_AlignmentW( 1.0f ),
	m_SeparationW( 1.0f ),
	m_CohesionW( 1.0f ),
	m_VisionRadius( 0.3f ),
	m_Speed( 7.0f ),
	m_Acceleration( 0.7f )
{

}

void SwarmSystem::Tick( float dt )
{
	for ( auto &agent : m_Components->Agents.GetContainer() )
	{
		if ( agent.second.MovementBehaviour != AgentComponent::Swarming )
		{
			continue;
		}

		int agentId = agent.first;
		auto &agentVelocity = m_Components->Velocities.Find( agentId ).Velocity;
		glm::vec3 swarmVelocity = m_Speed * ( GetSeparationDirection( agentId ) * m_SeparationW + GetAlignmentDirection( agentId ) * m_AlignmentW + GetCohesionDirection( agentId ) * m_CohesionW + GetBoundaryDirection( agentId ) * m_BoundaryW ) / ( m_SeparationW + m_AlignmentW + m_CohesionW + m_BoundaryW );
		glm::vec3 acceleration = m_Acceleration * ( swarmVelocity - agentVelocity );

		m_Components->Accelerations.Find( agentId ).Acceleration += acceleration;
	}
}

glm::vec3 SwarmSystem::GetSeparationDirection( int id )
{
	glm::vec3 separation( 0, 0, 0 );
	auto &mainAgentPos = m_Components->Positions.Find( id );

	for ( auto &agent : m_Components->Agents.GetContainer() )
	{
		if ( agent.first == id )
		{
			continue;
		}

		auto &agentPos = m_Components->Positions.Find( agent.first );
		glm::vec3 direction = mainAgentPos.Position - agentPos.Position;
		float distance = glm::length( direction );

		if ( distance < m_VisionRadius )
		{
			separation += Utils::UnitVector( direction ) / std::max( distance, 1e-6f );
		}
	}
	return Utils::UnitVector( separation );
}

glm::vec3 SwarmSystem::GetAlignmentDirection( int id )
{
	glm::vec3 alignment( 0, 0, 0 );
	auto &mainAgentPos = m_Components->Positions.Find( id );

	for ( auto &agent : m_Components->Agents.GetContainer() )
	{
		if ( agent.first == id )
		{
			continue;
		}

		auto &agentPos = m_Components->Positions.Find( agent.first );
		glm::vec3 direction = mainAgentPos.Position - agentPos.Position;
		double distance = glm::length( direction );

		if ( distance < m_VisionRadius )
		{
			auto &agentVel = m_Components->Velocities.Find( agent.first );

			alignment += Utils::UnitVector( agentVel.Velocity );
		}
	}
	return Utils::UnitVector( alignment );
}

glm::vec3 SwarmSystem::GetCohesionDirection( int id )
{
	glm::vec3 center( 0, 0, 0 );
	auto &mainAgentPos = m_Components->Positions.Find( id );
	int otherAgentsCnt = 0;

	for ( auto &agent : m_Components->Agents.GetContainer() )
	{
		if ( agent.first == id )
		{
			continue;
		}

		auto &agentPos = m_Components->Positions.Find( agent.first );
		glm::vec3 direction = mainAgentPos.Position - agentPos.Position;
		double distance = glm::length( direction );

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

glm::vec3 SwarmSystem::GetBoundaryDirection( int id )
{
	glm::vec3 boundary( 0, 0, 0 );
	auto &mainAgentPos = m_Components->Positions.Find( id );

	if ( mainAgentPos.Position.x + m_VisionRadius > m_Components->Map.MaxPositionX )
	{
		return glm::vec3( -1, 0, 0 );
	}
	if ( mainAgentPos.Position.x - m_VisionRadius < m_Components->Map.MinPositionX )
	{
		return glm::vec3( 1, 0, 0 );
	}
	if ( mainAgentPos.Position.y + m_VisionRadius > m_Components->Map.MaxPositionY )
	{
		return glm::vec3( 0, -1, 0 );
	}
	if ( mainAgentPos.Position.y - m_VisionRadius < m_Components->Map.MinPositionY )
	{
		return glm::vec3( 0, 1, 0 );
	}

	return glm::vec3( 0, 0, 0 );
}