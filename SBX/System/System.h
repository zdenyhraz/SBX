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

		while ( Enabled )
		{
			Tick( 1.f / 60.f );
			std::this_thread::sleep_for( std::chrono::microseconds( 100000 ) );
		}
	}

	void Stop()
	{
		Enabled = false;
	}

	virtual void Tick( float dt ) = 0;

protected:
	std::shared_ptr<ComponentVectors> Components;
	bool Enabled;

};