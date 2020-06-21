#pragma once
#include "Stdafx.h"
#include "System.h"

class TimeSystem : public System
{
public:

	TimeSystem( std::shared_ptr<ComponentVectors> components ) : System( components, "Time" )
	{

	}

	void Tick( double dt ) override
	{
		m_Components->Time.m_Time += dt;
		m_ConsoleTitle = "Time = " + std::to_string( m_Components->Time.m_Time );
		SetConsoleTitle( m_ConsoleTitle.c_str() );
	}

	void StartTime()
	{
		m_Components->Time.m_TimeRate = 1;
		LOG_INFO( "Time started" );
	}

	void StopTime()
	{
		m_Components->Time.m_TimeRate = 0;
		LOG_INFO( "Time stopped" );
	}

	void SetTimeRate( double timeRate )
	{
		m_Components->Time.m_TimeRate = timeRate;
		LOG_INFO( "Time rate set to {}", timeRate );
	}

private:
	std::string m_ConsoleTitle;
};
