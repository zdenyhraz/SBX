#pragma once
#include "Stdafx.h"
#include "System.h"
#include "MovementSystem.h"
#include "DrawSystem.h"
#include "RenderSystem.h"
#include "CommandLineSystem.h"
#include "TestSystem.h"
#include "TimeSystem.h"

class SystemVector
{
public:
	SystemVector( std::shared_ptr<ComponentVectors> components )
	{
		Systems.push_back( std::make_shared<TimeSystem>( components ) );
		Systems.push_back( std::make_shared<MovementSystem>( components ) );
		Systems.push_back( std::make_shared<DrawSystem>( components ) );
		Systems.push_back( std::make_shared<CommandLineSystem>( components ) );
		Systems.push_back( std::make_shared<TestSystem>( components ) );
	}

	void Run()
	{
		std::vector<std::thread> Threads;

		for ( auto &system : Systems )
			Threads.push_back( std::thread( &System::Run, system.get() ) );

		for ( auto &thread : Threads )
			thread.join();
	}

	void Stop()
	{
		for ( auto &system : Systems )
			system->Stop();
	}

private:
	std::vector<std::shared_ptr<System>> Systems;

};