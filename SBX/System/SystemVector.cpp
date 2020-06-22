#include "SystemVector.h"
#include "Movement/MovementSystem.h"
#include "Draw/DrawSystem.h"
#include "CommandLine/CommandLineSystem.h"
#include "Test/TestSystem.h"
#include "Time/TimeSystem.h"
#include "Utils/ThreadUtils.h"

SystemVector::SystemVector( std::shared_ptr<ComponentVectors> components )
{
	Systems.push_back( std::make_shared<TimeSystem>( components ) );
	Systems.push_back( std::make_shared<MovementSystem>( components ) );
	Systems.push_back( std::make_shared<DrawSystem>( components ) );
	Systems.push_back( std::make_shared<CommandLineSystem>( components ) );
	Systems.push_back( std::make_shared<TestSystem>( components ) );
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