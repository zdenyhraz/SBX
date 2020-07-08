#include "MovementSystem.h"
#include "Utils/MathUtils.h"

MovementSystem::MovementSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Movement" )
{

}

void MovementSystem::Tick()
{
	for ( auto &accel : m_Components->Accelerations.GetContainer() )
	{
		m_Components->Velocities.Find( accel.first ).Velocity += accel.second.Acceleration * m_Components->Time.GetDelta();
		accel.second.Clear();
	}

	for ( auto &vel : m_Components->Velocities.GetContainer() )
	{
		m_Components->Positions.Find( vel.first ).Position += vel.second.Velocity * m_Components->Time.GetDelta();
		Utils::Clamp( m_Components->Positions.Find( vel.first ).Position.x, m_Components->Map.MinPositionX, m_Components->Map.MaxPositionX );
		Utils::Clamp( m_Components->Positions.Find( vel.first ).Position.y, m_Components->Map.MinPositionY, m_Components->Map.MaxPositionX );
	}
}