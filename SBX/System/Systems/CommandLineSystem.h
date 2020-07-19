#pragma once
#include "System/System.h"

class CommandLineSystem : public System
{
public:

	CommandLineSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick( float dt ) override;

private:
	void ProcessCommand( const std::string &command );
	void ProcessStartTime();
	void ProcessStopTime();
	void ProcessSetTimeRate( double timerate );

	std::string m_Command;
};
