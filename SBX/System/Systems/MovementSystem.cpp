#include "MovementSystem.h"
#include "Utils/MathUtils.h"

MovementSystem::MovementSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers )
{

}

void MovementSystem::Tick( float dt )
{
	// update velocities from accelerations
	for ( auto &accel : m_Components->Accelerations.GetContainer() )
	{
		m_Components->Velocities.Find( accel.first ).Velocity += accel.second.Acceleration * m_Managers->m_TimeManager->GetDelta();
		accel.second.Acceleration = glm::vec3( 0, 0, 0 );
	}

	// update positions from velocities
	for ( auto &vel : m_Components->Velocities.GetContainer() )
	{
		m_Components->Positions.Find( vel.first ).Position += vel.second.Velocity * m_Managers->m_TimeManager->GetDelta();
		Utils::Clamp( m_Components->Positions.Find( vel.first ).Position.x, m_Components->Map.MinPositionX, m_Components->Map.MaxPositionX );
		Utils::Clamp( m_Components->Positions.Find( vel.first ).Position.y, m_Components->Map.MinPositionY, m_Components->Map.MaxPositionX );
	}
}