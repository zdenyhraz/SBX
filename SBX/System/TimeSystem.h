#pragma once
#include "Stdafx.h"
#include "System.h"

class TimeSystem : public System
{
public:

	TimeSystem( std::shared_ptr<ComponentVectors> components ):
		System( components, "Time" )
	{

	}

	void Tick() override
	{
		m_Components->Time.Advance();
		m_ConsoleTitle = "Time = " + std::to_string( m_Components->Time.GetTime() ) + ", TimeRate = " + std::to_string( m_Components->Time.GetTimeRate() ) + ", Delta = " + std::to_string( m_Components->Time.GetDelta() ) + ", Running = " + std::to_string( m_Components->Time.GetRunning() );
		SetConsoleTitle( m_ConsoleTitle.c_str() );
	}

private:
	std::string m_ConsoleTitle;
};
