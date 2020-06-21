#pragma once
#include "Stdafx.h"
#include "System.h"

class TestSystem : public System
{
public:

	TestSystem( std::shared_ptr<ComponentVectors> components ):
		System( components, "Test/Gravity", 10 )
	{

	}

	void Tick() override
	{
		for ( auto &accel : m_Components->Accelerations.Data )
		{
			const double gravity = 1.0;
			accel.second.x = m_Components->Positions.Find( accel.first ).x * -gravity;
			accel.second.y = m_Components->Positions.Find( accel.first ).y * -gravity;
		}
	}

private:
};
