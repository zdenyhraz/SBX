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
		Time = std::make_unique<TimeSystem>( components );
		Movement = std::make_unique<MovementSystem>( components );
		Draw = std::make_unique<DrawSystem>( components );
		CommandLine = std::make_unique<CommandLineSystem>( components, Time );
		Test = std::make_unique<TestSystem>( components );
	}

	void Run()
	{
		std::vector<std::thread> threads;
		threads.push_back( std::thread( &System::Run, Time.get() ) );
		threads.push_back( std::thread( &System::Run, Movement.get() ) );
		threads.push_back( std::thread( &System::Run, Draw.get() ) );
		threads.push_back( std::thread( &System::Run, CommandLine.get() ) );
		threads.push_back( std::thread( &System::Run, Test.get() ) );


		for ( auto &thread : threads )
		{
			thread.join();
		}
	}

	void Stop()
	{
		Time->Stop();
		Movement->Stop();
		Draw->Stop();
		CommandLine->Stop();
		Test->Stop();
	}

private:
	std::shared_ptr<TimeSystem> Time;
	std::shared_ptr<MovementSystem> Movement;
	std::shared_ptr<DrawSystem> Draw;
	std::shared_ptr<CommandLineSystem> CommandLine;
	std::shared_ptr<TestSystem> Test;


};