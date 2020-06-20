#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components ): Components( components )
	{

	}

	void Run()
	{
		Enabled = true;

		while ( Enabled )
		{
			Tick( 1 );
		}
	}

	void Stop()
	{
		Enabled = false;
	}

	virtual void Tick( double dt ) = 0;

protected:
	std::shared_ptr<ComponentVectors> Components;
	bool Enabled;

};