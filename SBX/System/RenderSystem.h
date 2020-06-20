#pragma once
#include "Stdafx.h"
#include "System.h"

class RenderSystem : public System
{
public:

	RenderSystem( std::shared_ptr<ComponentVectors> components ): System( components, "render" )
	{

	}

	void Tick( double dt ) override
	{

	}

private:
};
