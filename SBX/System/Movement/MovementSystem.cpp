#include "MovementSystem.h"

MovementSystem::MovementSystem( std::shared_ptr<ComponentVectors> components ) :
	System( components, "Movement" )
{

}

void MovementSystem::Tick()
{
	for ( auto &accel : m_Components->Accelerations.Data )
	{
		m_Components->Velocities.Find( accel.first ).Velocity += accel.second.Acceleration * m_Components->Time.GetDelta();
	}

	for ( auto &vel : m_Components->Velocities.Data )
	{
		m_Components->Positions.Find( vel.first ).Position += vel.second.Velocity * m_Components->Time.GetDelta();
	}
}