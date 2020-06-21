#pragma once
#include "Stdafx.h"
#include "System.h"

class MovementSystem : public System
{
public:

	MovementSystem( std::shared_ptr<ComponentVectors> components ) : System( components, "Movement" )
	{

	}

	void Tick() override
	{
		for ( auto &accel : m_Components->Accelerations.Data )
		{
			m_Components->Velocities.Find( accel.first ).x += accel.second.x * m_Components->Time.m_Delta;
			m_Components->Velocities.Find( accel.first ).y += accel.second.y * m_Components->Time.m_Delta;
			m_Components->Velocities.Find( accel.first ).z += accel.second.z * m_Components->Time.m_Delta;
		}

		for ( auto &vel : m_Components->Velocities.Data )
		{
			m_Components->Positions.Find( vel.first ).x += vel.second.x * m_Components->Time.m_Delta;
			m_Components->Positions.Find( vel.first ).y += vel.second.y * m_Components->Time.m_Delta;
			m_Components->Positions.Find( vel.first ).z += vel.second.z * m_Components->Time.m_Delta;
		}

	}

private:
};
