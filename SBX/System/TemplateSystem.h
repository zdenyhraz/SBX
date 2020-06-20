#pragma once
#include "Stdafx.h"
#include "System.h"

class TemplateSystem : public System
{
public:

	TemplateSystem( std::shared_ptr<ComponentVectors> components ): System( components, "template" )
	{

	}

	void Tick( double dt ) override
	{

	}

private:
};
