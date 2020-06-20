#pragma once
#include "Stdafx.h"
#include "System.h"

class VelocitySystem: public System
{
public:

	VelocitySystem( std::shared_ptr<ComponentVectors> components ): System( components )
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
	}

private:
};
