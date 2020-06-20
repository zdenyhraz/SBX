#pragma once
#include "Stdafx.h"
#include "System.h"

class DrawSystem : public System
{
public:

	DrawSystem( ComponentVectors &ComponentVectors ) : ComponentVectors( ComponentVectors )
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
