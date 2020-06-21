#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "Utils/ThreadUtils.h"
#include "Utils/TimeUtils.h"
#include "Utils/MathUtils.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components, std::string &&name, double refreshRate = 100 ):
		m_Components( components ),
		m_Name( std::move( name ) ),
		m_Enabled( true ),
		m_RefreshRate( refreshRate )
	{
		m_TargetTickDurationSec = 1. / m_RefreshRate;
		m_TargetTickDuration = ( long long )( m_TargetTickDurationSec * 1e6 );
	}

	void Run()
	{
		LOG_DEBUG( "Running <{}> system on thread {}", m_Name, Utils::ThisThreadId() );
		m_Enabled = true;

		while ( m_Enabled )
		{
			m_TickStart = Utils::GetTimeNow();
			Tick();
			m_TickEnd = Utils::GetTimeNow();

			std::this_thread::sleep_for( std::chrono::microseconds( m_TargetTickDuration - Utils::GetDuration( m_TickStart, m_TickEnd ) ) );
		}
	}

	void Stop()
	{
		m_Enabled = false;
	}

	virtual void Tick() = 0;

protected:
	std::shared_ptr<ComponentVectors> m_Components;
	std::string m_Name;
	bool m_Enabled;
	int m_RefreshRate;
	double m_TargetTickDurationSec;
	long long m_TargetTickDuration;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickStart;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickEnd;

};