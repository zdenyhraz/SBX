#include "CommandLineSystem.h"

CommandLineSystem::CommandLineSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "CommandLine", true )
{

}

void CommandLineSystem::Tick()
{
	getline( std::cin, m_Command );
	ProcessCommand( m_Command );
}

void CommandLineSystem::ProcessCommand( const std::string &command )
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
		double timerate = std::stod( command.substr( command.find( " " ) + 1 ) );
		ProcessSetTimeRate( timerate );
		return;
	}

	LOG_DEBUG( "Unknown command '{}'", command );
}

void CommandLineSystem::ProcessStartTime()
{
	m_Components->Past->Time.StartTime();
}

void CommandLineSystem::ProcessStopTime()
{
	m_Components->Past->Time.StopTime();
}

void CommandLineSystem::ProcessSetTimeRate( double timerate )
{
	m_Components->Past->Time.SetTimeRate( timerate );
}