#pragma once
#include "Stdafx.h"
#include "System.h"

class TestSystem : public System
{
public:

	TestSystem( std::shared_ptr<ComponentVectors> components ) : System( components, "Test" )
	{

	}

	void Tick( double dt ) override
	{
		for ( auto &accel : m_Components->Accelerations.Data )
		{
			accel.second.ax = m_Components->Positions.Find( accel.first ).x * -10.5;
			accel.second.ay = m_Components->Positions.Find( accel.first ).y * -10.5;

			//accel.second.ax += Utils::Rand11() * 0.01;
			//accel.second.ay += Utils::Rand11() * 0.01;
		}

		for ( auto &vel : m_Components->Velocities.Data )
		{
			vel.second.vx += Utils::Rand11() * 0.01;
			vel.second.vy += Utils::Rand11() * 0.01;

		}
	}

private:
};
