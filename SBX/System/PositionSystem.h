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
		for ( auto &velocity : Components->Velocities.Data )
		{
			Components->Positions.Find( velocity.first ).x += velocity.second.vx * dt;
			Components->Positions.Find( velocity.first ).y += velocity.second.vy * dt;
			Components->Positions.Find( velocity.first ).z += velocity.second.vz * dt;
		}
	}

private:
};
