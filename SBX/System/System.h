#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "Utils/ThreadUtils.h"
#include "Utils/TimeUtils.h"


class System
{
public:
	System( std::shared_ptr<ComponentVectors> components ): m_Components( components )
	{

	}

	void Run()
	{
		LOG_DEBUG( "Running system on thread {}", Utils::ThisThreadId() );
		m_Enabled = true;

		while ( m_Enabled )
		{
			m_TickStart = Utils::GetCurrentTime();
			Tick( m_TargetTickDurationSec );
			m_TickEnd = Utils::GetCurrentTime();

			std::this_thread::sleep_for( std::chrono::microseconds( m_TargetTickDuration - Utils::GetDuration( m_TickStart, m_TickEnd ) ) );
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
	double m_TargetTickDurationSec = 1. / m_RefreshRate;
	long long m_TargetTickDuration = ( long long )( m_TargetTickDurationSec * 1e6 );
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickStart;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickEnd;

};