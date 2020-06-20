#pragma once
#include "Stdafx.h"
#include "System.h"

class DrawSystem : public System
{
public:

	DrawSystem( std::shared_ptr<ComponentVectors> ComponentVectors ) : ComponentVectors( ComponentVectors )
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
	std::shared_ptr<ComponentVectors> ComponentVectors;
};
