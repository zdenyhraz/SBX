#pragma once
#include "Stdafx.h"
#include "System.h"

class RenderSystem : public System
{
public:

	RenderSystem( std::shared_ptr<ComponentVectors> ComponentVectors )
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
