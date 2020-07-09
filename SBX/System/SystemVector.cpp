#include "SystemVector.h"
#include "Utils/ThreadUtils.h"
#include "Systems/MovementSystem.h"
#include "Systems/DrawSystem.h"
#include "Systems/CommandLineSystem.h"
#include "Systems/TimeSystem.h"
#include "Systems/RenderSystem.h"
#include "Systems/LogicSystem.h"

SystemVector::SystemVector( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers )
{
	Systems.push_back( std::make_shared<DrawSystem>( components, managers ) );
	Systems.push_back( std::make_shared<RenderSystem>( components, managers ) );
	Systems.push_back( std::make_shared<CommandLineSystem>( components, managers ) );
	Systems.push_back( std::make_shared<TimeSystem>( components, managers ) );
	Systems.push_back( std::make_shared<MovementSystem>( components, managers ) );
	Systems.push_back( std::make_shared<LogicSystem>( components, managers ) );
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