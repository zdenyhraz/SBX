#pragma once
#include "Stdafx.h"
#include "System.h"

class CommandLineSystem : public System
{
public:

	CommandLineSystem( std::shared_ptr<ComponentVectors> components ):
		System( components, "CommandLine", 10 )
	{

	}

	void Tick() override
	{
		getline( std::cin, m_Command );
		ProcessCommand( m_Command );
	}

	void ProcessCommand( const std::string &command )
	{
		if ( command.find( "start" ) != std::string::npos )
		{
			LOG_DEBUG( "StartTime command registered" );
			ProcessStartTime();
			return;
		}

		if ( command.find( "stop" ) != std::string::npos )
		{
			LOG_DEBUG( "StopTime command registered" );
			ProcessStopTime();
			return;
		}

		if ( command.find( "timerate" ) != std::string::npos )
		{
			LOG_DEBUG( "SetTimeRate command registered" );
			ProcessSetTimeRate();
			return;
		}

		LOG_DEBUG( "Unknown command '{}'", command );
	}

	void ProcessStartTime()
	{
		m_Components->Time.StartTime();
	}

	void ProcessStopTime()
	{
		m_Components->Time.StopTime();
	}

	void ProcessSetTimeRate()
	{
		m_Components->Time.SetTimeRate( 0.1 );
	}

private:
	std::string m_Command;
};
