#pragma once
#include "Stdafx.h"
#include "System.h"
#include "Sandbox/CommandLineParser.h"

class CommandLineSystem : public System
{
public:

	CommandLineSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<TimeSystem> timesystem ) : System( components, "CommandLine" )
	{
		m_CommandLineParser = std::make_shared<CommandLineParser>( timesystem );
	}

	void Tick( double dt ) override
	{
		getline( std::cin, m_Command );
		m_CommandLineParser->ProcessCommand( m_Command );
	}

private:
	std::string m_Command;
	std::shared_ptr<CommandLineParser> m_CommandLineParser;
};
