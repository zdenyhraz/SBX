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
		Systems.push_back( std::make_unique<TimeSystem>( components ) );
		Systems.push_back( std::make_unique<MovementSystem>( components ) );
		Systems.push_back( std::make_unique<DrawSystem>( components ) );
		Systems.push_back( std::make_unique<CommandLineSystem>( components ) );
		Systems.push_back( std::make_unique<TestSystem>( components ) );
	}

	void Run()
	{
		std::vector<std::thread> threads;

		for ( auto &system : Systems )
		{
			threads.push_back( std::thread( &System::Run, system.get() ) );
		}

		for ( auto &thread : threads )
		{
			thread.join();
		}
	}

	void Stop()
	{
		for ( auto &system : Systems )
		{
			system->Stop();
		}
	}

private:
	std::vector<std::shared_ptr<System>> Systems;

};