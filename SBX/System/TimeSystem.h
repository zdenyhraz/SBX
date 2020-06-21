#pragma once
#include "Stdafx.h"
#include "System.h"

class TimeSystem : public System
{
public:

	TimeSystem( std::shared_ptr<ComponentVectors> components ) : System( components, "Time" )
	{

	}

	void Tick() override
	{
		m_Components->Time.Advance();
		m_ConsoleTitle = "Time = " + std::to_string( m_Components->Time.GetTime() ) + ", TimeRate = " + std::to_string( m_Components->Time.GetTimeRate() );
		SetConsoleTitle( m_ConsoleTitle.c_str() );
	}

	void StartTime()
	{
		m_Components->Time.SetTimeRate( 1 );
		LOG_INFO( "Time started at {}", m_Components->Time.GetTime() );
	}

	void StopTime()
	{
		m_Components->Time.SetTimeRate( 0 );
		LOG_INFO( "Time stopped at {}", m_Components->Time.GetTime() );
	}

	void SetTimeRate( double timeRate )
	{
		m_Components->Time.SetTimeRate( timeRate );
		LOG_INFO( "Time rate set to {}", timeRate );
	}

private:
	std::string m_ConsoleTitle;
};
