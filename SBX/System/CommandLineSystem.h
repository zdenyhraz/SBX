#pragma once
#include "Stdafx.h"
#include "System.h"

class CommandLineSystem : public System
{
public:

	CommandLineSystem( std::shared_ptr<ComponentVectors> components );

	void Tick() override;

	void ProcessCommand( const std::string &command );

	void ProcessStartTime();

	void ProcessStopTime();

	void ProcessSetTimeRate( double timerate );

private:
	std::string m_Command;
};
