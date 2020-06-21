#pragma once
#include "Stdafx.h"
#include "System/TimeSystem.h"

class CommandLineManager
{
public:
	CommandLineManager( std::shared_ptr<TimeSystem> timesystem ):
		m_TimeSystem( timesystem )
	{

	}

	void ProcessCommand( const std::string &command )
	{
		if ( command.find( "start" ) != std::string::npos )
		{
			LOG_DEBUG( "Start command registered" );
			ProcessStart();
			return;
		}

		if ( command.find( "stop" ) != std::string::npos )
		{
			LOG_DEBUG( "Stop command registered" );
			ProcessStop();
			return;
		}

		LOG_DEBUG( "Unknown command '{}'", command );
	}

	void ProcessStart()
	{
		m_TimeSystem->StartTime();
	}

	void ProcessStop()
	{
		m_TimeSystem->StopTime();
	}



private:
	std::shared_ptr<TimeSystem> m_TimeSystem;

};