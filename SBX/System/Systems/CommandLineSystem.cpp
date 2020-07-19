#include "CommandLineSystem.h"

CommandLineSystem::CommandLineSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers )
{

}

void CommandLineSystem::Run()
{
	while ( true )
	{
		getline( std::cin, m_Command );
		ProcessCommand( m_Command );
	}
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
		float timerate = std::stof( command.substr( command.find( " " ) + 1 ) );
		ProcessSetTimeRate( timerate );
		return;
	}

	LOG_DEBUG( "Unknown command '{}'", command );
}

void CommandLineSystem::ProcessStartTime()
{
	m_Managers->m_TimeManager->StartTime();
}

void CommandLineSystem::ProcessStopTime()
{
	m_Managers->m_TimeManager->StopTime();
}

void CommandLineSystem::ProcessSetTimeRate( float timerate )
{
	m_Managers->m_TimeManager->SetTimeRate( timerate );
}