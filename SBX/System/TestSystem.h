#pragma once
#include "Stdafx.h"
#include "System.h"

class TestSystem : public System
{
public:

	TestSystem( std::shared_ptr<ComponentVectors> components ) : System( components, "test" )
	{

	}

	void Tick( double dt ) override
	{
		for ( auto &accel : m_Components->Accelerations.Data )
		{
			//accel.second.ax += Utils::Rand11() * 0.01 * dt;
			//accel.second.ay += Utils::Rand11() * 0.01 * dt;

			accel.second.ax = m_Components->Positions.Find( accel.first ).y * -1.0;
			accel.second.ay = m_Components->Positions.Find( accel.first ).x * -1.0;
		}
	}

private:
};
