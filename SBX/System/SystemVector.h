#pragma once
#include "Stdafx.h"
#include "System.h"
#include "MovementSystem.h"
#include "DrawSystem.h"
#include "RenderSystem.h"
#include "CommandLineSystem.h"
#include "TestSystem.h"

class SystemVector
{
public:
	SystemVector( std::shared_ptr<ComponentVectors> components )
	{
		Movement = std::make_unique<MovementSystem>( components );
		Draw = std::make_unique<DrawSystem>( components );
		Render = std::make_unique<RenderSystem>( components );
		CommandLine = std::make_unique<CommandLineSystem>( components );
		Test = std::make_unique<TestSystem>( components );
	}

	void Run()
	{
		std::vector<std::thread> threads;
		threads.push_back( std::thread( &MovementSystem::Run, Movement.get() ) );
		threads.push_back( std::thread( &DrawSystem::Run, Draw.get() ) );
		threads.push_back( std::thread( &RenderSystem::Run, Render.get() ) );
		threads.push_back( std::thread( &CommandLineSystem::Run, CommandLine.get() ) );
		threads.push_back( std::thread( &TestSystem::Run, Test.get() ) );

		for ( auto &thread : threads )
		{
			thread.join();
		}
	}

	void Stop()
	{
		Movement->Stop();
		Draw->Stop();
		Render->Stop();
		CommandLine->Stop();
		Test->Stop();
	}

private:
	std::unique_ptr<MovementSystem> Movement;
	std::unique_ptr<DrawSystem> Draw;
	std::unique_ptr<RenderSystem> Render;
	std::unique_ptr<CommandLineSystem> CommandLine;
	std::unique_ptr<TestSystem> Test;


};