#include "CommandLineSystem.h"

CommandLineSystem::CommandLineSystem( std::shared_ptr<ComponentVectors> components ) :
	System( components, "CommandLine", 10 )
{

}

void CommandLineSystem::Tick()
{
	getline( std::cin, m_Command );
	ProcessCommand( m_Command );
}

void CommandLineSystem::ProcessCommand( const std::string &command )
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

void CommandLineSystem::ProcessRun()
{
	//m_SystemManager->Run();
}

void CommandLineSystem::ProcessEnd()
{
	//m_SystemManager->End();
}

void CommandLineSystem::ProcessStartTime()
{
	m_Components->Time.StartTime();
}

void CommandLineSystem::ProcessStopTime()
{
	m_Components->Time.StopTime();
}

void CommandLineSystem::ProcessSetTimeRate( double timerate )
{
	m_Components->Time.SetTimeRate( timerate );
}