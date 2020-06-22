#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "Utils/ThreadUtils.h"
#include "Utils/TimeUtils.h"
#include "Utils/MathUtils.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components, std::string &&name, double refreshRate = TimeComponent::RefreshRate ):
		m_Components( components ),
		m_Name( std::move( name ) ),
		m_Enabled( true ),
		m_RefreshRate( refreshRate )
	{
		m_TargetTickDuration = ( long long )( 1. / m_RefreshRate * 1e6 );
	}

	void Run()
	{
		LOG_DEBUG( "Running <{}> system on thread {} with {} Hz refresh rate", m_Name, Utils::ThisThreadId(), m_RefreshRate );
		m_Enabled = true;

		while ( m_Enabled )
		{
			m_TickStart = Utils::GetTimeNow();
			Tick();
			m_TickEnd = Utils::GetTimeNow();

			std::this_thread::sleep_for( std::chrono::microseconds( std::max( m_TargetTickDuration - Utils::GetDuration( m_TickStart, m_TickEnd ), 0ll ) ) );
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
	double m_RefreshRate;
	long long m_TargetTickDuration;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickStart;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickEnd;

};