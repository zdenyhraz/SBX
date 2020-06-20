#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components ): Components( components )
	{

	}

	virtual void Run() = 0;
	virtual void Stop() = 0;
	virtual void Tick( double dt ) = 0;

protected:
	std::shared_ptr<ComponentVectors> Components;

};