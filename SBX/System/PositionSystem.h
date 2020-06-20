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

	}

private:
};
