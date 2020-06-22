#pragma once
#include "Stdafx.h"
#include "System.h"

class CommandLineSystem : public System
{
public:

	CommandLineSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<SystemVector> systems ):
		System( components, systems, "CommandLine", 10 )
	{

	}

	void Tick() override
	{
		getline( std::cin, m_Command );
		ProcessCommand( m_Command );
	}

	void ProcessCommand( const std::string &command )
	{
		if ( command.find( "run" ) != std::string::npos )
		{
			LOG_DEBUG( "Run command registered" );
			ProcessRun();
			return;
		}

		if ( command.find( "end" ) != std::string::npos )
		{
			LOG_DEBUG( "End command registered" );
			ProcessEnd();
			return;
		}

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
			double timerate = std::stod( command.substr( command.find( " " ) + 1 ) );
			ProcessSetTimeRate( timerate );
			return;
		}

		LOG_DEBUG( "Unknown command '{}'", command );
	}

	void ProcessRun()
	{
		//m_Systems->Run();
	}

	void ProcessEnd()
	{
		//m_Systems->End();
	}

	void ProcessStartTime()
	{
		m_Components->Time.StartTime();
	}

	void ProcessStopTime()
	{
		m_Components->Time.StopTime();
	}

	void ProcessSetTimeRate( double timerate )
	{
		m_Components->Time.SetTimeRate( timerate );
	}

private:
	std::string m_Command;
};
