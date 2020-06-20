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
			accel.second.x = m_Components->Positions.Find( accel.first ).x * -10.5;
			accel.second.y = m_Components->Positions.Find( accel.first ).y * -10.5;

			//accel.second.x += Utils::Rand11() * 0.01;
			//accel.second.y += Utils::Rand11() * 0.01;
		}

		for ( auto &vel : m_Components->Velocities.Data )
		{
			vel.second.x += Utils::Rand11() * 0.01;
			vel.second.y += Utils::Rand11() * 0.01;

		}
	}

private:
};
