#pragma once
#include "Stdafx.h"
#include "System.h"

class DrawSystem : public System
{
public:

	DrawSystem( std::shared_ptr<ComponentVectors> ComponentVectors )
	{
		Components = ComponentVectors;
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
};
