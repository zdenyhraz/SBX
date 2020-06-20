#pragma once
#include "Stdafx.h"
#include "System.h"

class VelocitySystem: public System
{
public:

	VelocitySystem( ComponentVectors &ComponentVectors ) : ComponentVectors( ComponentVectors )
	{

	}

	void Run() override
	{

	}

	void Stop() override
	{

	}

	void Tick( double dt ) override
	{

	}

private:
	ComponentVectors &ComponentVectors;
};
