#pragma once
#include "Stdafx.h"
#include "System.h"

class RenderSystem : public System
{
public:

	RenderSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<SystemVector> systems ):
		System( components, systems, "Render" )
	{

	}

	void Tick() override
	{

	}

private:
};
