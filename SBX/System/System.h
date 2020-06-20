#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "Utils/ThreadUtils.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components ): Components( components )
	{

	}

	void Run()
	{
		LOG_DEBUG( "Running system on thread {}", ThisThreadId() );
		Enabled = true;
		double dt = 1. / RefreshRate;

		while ( Enabled )
		{
			Tick( dt );
			std::this_thread::sleep_for( std::chrono::microseconds( ( int )( dt * 1e6 ) ) );
		}
	}

	void Stop()
	{
		Enabled = false;
	}

	virtual void Tick( double dt ) = 0;

protected:
	std::shared_ptr<ComponentVectors> Components;
	bool Enabled = true;
	int RefreshRate = 60;
};