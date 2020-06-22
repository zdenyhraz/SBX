#include "SystemVector.h"
#include "MovementSystem.h"
#include "DrawSystem.h"
#include "CommandLineSystem.h"
#include "TestSystem.h"
#include "TimeSystem.h"

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
	std::vector<std::thread> Threads;

	for ( auto &system : Systems )
		Threads.push_back( std::thread( &System::Run, system.get() ) );

	for ( auto &thread : Threads )
		thread.detach();
}

void SystemVector::Kill()
{
	for ( auto &system : Systems )
		system->Kill();
}