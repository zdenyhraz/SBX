#pragma once
#include "Stdafx.h"
#include "System.h"

class TestSystem : public System
{
public:

	TestSystem( std::shared_ptr<ComponentVectors> components ):
		System( components, "Test/Gravity" )
	{

	}

	void Tick() override
	{
		for ( auto &accel : m_Components->Accelerations.Data )
		{
			constexpr double gravity = 1.0;
			accel.second.Acceleration = m_Components->Positions.Find( accel.first ).Position * -gravity;
		}
	}

private:
};
