#pragma once
#include "Stdafx.h"
#include "System.h"

class VelocitySystem: public System
{
public:
	VelocitySystem( ComponentVectors &componentVectors ) : ComponentVectors( componentVectors ) {}

	void Run() override
	{

	}

	void Tick( double dt ) override
	{

	}

private:
	ComponentVectors &ComponentVectors;

};
