#pragma once
#include "Stdafx.h"
#include "System.h"

class PositionSystem : public System
{
public:

	PositionSystem( std::shared_ptr<ComponentVectors> components ): System( components )
	{

	}

	void Tick( double dt ) override
	{
		for ( auto &vel : m_Components->Velocities.Data )
		{
			m_Components->Positions.Find( vel.first ).x += vel.second.vx * dt;
			m_Components->Positions.Find( vel.first ).y += vel.second.vy * dt;
			m_Components->Positions.Find( vel.first ).z += vel.second.vz * dt;
		}
	}

private:
};
