#pragma once
#include "Stdafx.h"
#include "System.h"

class TemplateSystem : public System
{
public:

	TemplateSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<SystemVector> systems ):
		System( components, systems, "Template" )
	{

	}

	void Tick() override
	{

	}

private:
};
