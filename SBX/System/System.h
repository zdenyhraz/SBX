#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "Utils/ThreadUtils.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components ): m_Components( components )
	{

	}

	void Run()
	{
		LOG_DEBUG( "Running system on thread {}", ThisThreadId() );
		m_Enabled = true;
		double dt = 1. / m_RefreshRate;

		while ( m_Enabled )
		{
			Tick( dt );
			std::this_thread::sleep_for( std::chrono::microseconds( ( int )( dt * 1e6 ) ) );
		}
	}

	void Stop()
	{
		m_Enabled = false;
	}

	virtual void Tick( double dt ) = 0;

protected:
	std::shared_ptr<ComponentVectors> m_Components;
	bool m_Enabled = true;
	int m_RefreshRate = 60;
};