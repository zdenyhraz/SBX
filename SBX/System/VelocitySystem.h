#pragma once
#include "Stdafx.h"
#include "System.h"

class VelocitySystem: public System
{
public:

	VelocitySystem( std::shared_ptr<ComponentVectors> components ): System( components )
	{

	}

	void Tick( float dt ) override
	{

	}

private:
};
