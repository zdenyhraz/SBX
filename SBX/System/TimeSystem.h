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
		m_Components->Time.m_Time += m_Components->Time.m_Delta * m_Components->Time.m_TimeRate;
		m_ConsoleTitle = "Time = " + std::to_string( m_Components->Time.m_Time ) + ", TimeRate = " + std::to_string( m_Components->Time.m_TimeRate );
		SetConsoleTitle( m_ConsoleTitle.c_str() );
	}

	void StartTime()
	{
		m_Components->Time.m_TimeRate = 1;
		LOG_INFO( "Time started at {}", m_Components->Time.m_Time );
	}

	void StopTime()
	{
		m_Components->Time.m_TimeRate = 0;
		LOG_INFO( "Time stopped at {}", m_Components->Time.m_Time );
	}

	void SetTimeRate( double timeRate )
	{
		m_Components->Time.m_TimeRate = timeRate;
		LOG_INFO( "Time rate set to {}", timeRate );
	}

private:
	std::string m_ConsoleTitle;
};
