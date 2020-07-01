#include "SystemVector.h"
#include "Utils/ThreadUtils.h"
#include "Movement/MovementSystem.h"
#include "Draw/DrawSystem.h"
#include "CommandLine/CommandLineSystem.h"
#include "Attractor/AttractorSystem.h"
#include "Time/TimeSystem.h"
#include "Agent/AgentSystem.h"

SystemVector::SystemVector( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers )
{
	Systems.push_back( std::make_shared<TimeSystem>( components, managers ) );
	Systems.push_back( std::make_shared<MovementSystem>( components, managers ) );
	Systems.push_back( std::make_shared<DrawSystem>( components, managers ) );
	Systems.push_back( std::make_shared<CommandLineSystem>( components, managers ) );
	Systems.push_back( std::make_shared<AgentSystem>( components, managers ) );
}

void SystemVector::Run()
{
	LOG_DEBUG( "Running systems" );

	std::vector<std::thread> Threads;

	for ( auto &system : Systems )
		Threads.push_back( std::thread( &System::Run, system.get() ) );

	for ( auto &thread : Threads )
		thread.detach();
}

void SystemVector::Kill()
{
	LOG_DEBUG( "Killing systems" );

	for ( auto &system : Systems )
		system->Kill();
}