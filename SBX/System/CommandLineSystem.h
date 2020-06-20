#pragma once
#include "Stdafx.h"
#include "System.h"

class CommandLineSystem : public System
{
public:

	CommandLineSystem( std::shared_ptr<ComponentVectors> components ) : System( components, "CommandLine" )
	{

	}

	void Tick( double dt ) override
	{
		getline( std::cin, Command );
		LOG_DEBUG( "Command line registered command '{}'", Command );
	}

private:
	std::string Command;

};
