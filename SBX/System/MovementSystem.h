#pragma once
#include "Stdafx.h"
#include "System.h"

class MovementSystem : public System
{
public:

	MovementSystem( std::shared_ptr<ComponentVectors> components ) : System( components, "movement" )
	{

	}

	void Tick( double dt ) override
	{
		for ( auto &accel : m_Components->Accelerations.Data )
		{
			m_Components->Velocities.Find( accel.first ).vx += accel.second.ax * dt;
			m_Components->Velocities.Find( accel.first ).vy += accel.second.ay * dt;
			m_Components->Velocities.Find( accel.first ).vz += accel.second.az * dt;
		}

		for ( auto &vel : m_Components->Velocities.Data )
		{
			m_Components->Positions.Find( vel.first ).x += vel.second.vx * dt;
			m_Components->Positions.Find( vel.first ).y += vel.second.vy * dt;
			m_Components->Positions.Find( vel.first ).z += vel.second.vz * dt;
		}

	}

private:
};
