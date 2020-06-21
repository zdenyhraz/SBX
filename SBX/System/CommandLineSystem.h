#pragma once
#include "Stdafx.h"
#include "System.h"
#include "Manager/CommandLineManager.h"

class CommandLineSystem : public System
{
public:

	CommandLineSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<TimeSystem> timesystem ) : System( components, "CommandLine" )
	{
		m_CommandLineManager = std::make_shared<CommandLineManager>( timesystem );
	}

	void Tick() override
	{
		getline( std::cin, m_Command );
		m_CommandLineManager->ProcessCommand( m_Command );
	}

private:
	std::string m_Command;
	std::shared_ptr<CommandLineManager> m_CommandLineManager;
};
