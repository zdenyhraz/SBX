#include "MovementSystem.h"
#include "Utils/MathUtils.h"
#include "Agent/AttractorAgentSystem.h"
#include "Agent/AvoidanceAgentSystem.h"
#include "Agent/SeekingAgentSystem.h"
#include "Agent/SwarmAgentSystem.h"

MovementSystem::MovementSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Movement" )
{
	//m_SubSystems.push_back( std::make_shared<AvoidanceAgentSystem>( components, managers ) );
	//m_SubSystems.push_back( std::make_shared<SeekingAgentSystem>( components, managers ) );
	m_SubSystems.push_back( std::make_shared<AttractorAgentSystem>( components, managers ) );
	m_SubSystems.push_back( std::make_shared<SwarmAgentSystem>( components, managers ) );
}

void MovementSystem::Tick()
{
	for ( auto &system : m_SubSystems )
	{
		system->Tick();
	}

	for ( auto &accel : m_Components->Past->Accelerations.GetContainer() )
	{
		m_Components->Past->Velocities.Find( accel.first ).Velocity += accel.second.Acceleration * m_Components->Past->Time.GetDelta();
		accel.second.Acceleration = cv::Point2d( 0, 0 );
	}

	for ( auto &vel : m_Components->Past->Velocities.GetContainer() )
	{
		m_Components->Past->Positions.Find( vel.first ).Position += vel.second.Velocity * m_Components->Past->Time.GetDelta();
		Utils::Clamp( m_Components->Past->Positions.Find( vel.first ).Position.x, m_Components->Past->Map.MinPositionX, m_Components->Past->Map.MaxPositionX );
		Utils::Clamp( m_Components->Past->Positions.Find( vel.first ).Position.y, m_Components->Past->Map.MinPositionY, m_Components->Past->Map.MaxPositionX );
	}
}