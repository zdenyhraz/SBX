#pragma once
#include "Stdafx.h"
#include "System.h"

class DrawSystem : public System
{
public:

	DrawSystem( std::shared_ptr<ComponentVectors> components ): System( components )
	{

	}

	void Tick( double dt ) override
	{

	}

private:
};