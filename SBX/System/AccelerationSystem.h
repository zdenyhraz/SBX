#pragma once
#include "Stdafx.h"
#include "System.h"

class AccelerationSystem : public System
{
public:

	AccelerationSystem( std::shared_ptr<ComponentVectors> components ): System( components, "acceleration" )
	{

	}

	void Tick( double dt ) override
	{

	}

private:
};
