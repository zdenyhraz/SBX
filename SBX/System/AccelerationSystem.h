#pragma once
#include "Stdafx.h"
#include "System.h"

class AccelerationSystem : public System
{
public:

	AccelerationSystem( std::shared_ptr<ComponentVectors> components ): System( components )
	{

	}

	void Tick( float dt ) override
	{

	}

private:
};
