#pragma once
#include "Stdafx.h"
#include "System.h"
#include "PositionSystem.h"
#include "VelocitySystem.h"
#include "AccelerationSystem.h"
#include "DrawSystem.h"
#include "RenderSystem.h"
#include "CommandLineSystem.h"

class SystemVector
{
public:
	SystemVector( std::shared_ptr<ComponentVectors> components )
	{
		Position = std::make_unique<PositionSystem>( components );
		Velocity = std::make_unique<VelocitySystem>( components );
		Acceleration = std::make_unique<AccelerationSystem>( components );
		Draw = std::make_unique<DrawSystem>( components );
		Render = std::make_unique<RenderSystem>( components );
		CommandLine = std::make_unique<CommandLineSystem>( components );

	}

	void Run()
	{
		std::vector<std::thread> threads;
		threads.push_back( std::thread( &PositionSystem::Run, Position.get() ) );
		threads.push_back( std::thread( &VelocitySystem::Run, Velocity.get() ) );
		threads.push_back( std::thread( &AccelerationSystem::Run, Acceleration.get() ) );
		threads.push_back( std::thread( &DrawSystem::Run, Draw.get() ) );
		threads.push_back( std::thread( &RenderSystem::Run, Render.get() ) );
		threads.push_back( std::thread( &CommandLineSystem::Run, CommandLine.get() ) );


		for ( auto &thread : threads )
		{
			thread.join();
		}

	}

	void Stop()
	{
		Position->Stop();
		Velocity->Stop();
		Acceleration->Stop();
		Draw->Stop();
		Render->Stop();
		CommandLine->Stop();
	}

private:
	std::unique_ptr<PositionSystem> Position;
	std::unique_ptr<VelocitySystem> Velocity;
	std::unique_ptr<AccelerationSystem> Acceleration;
	std::unique_ptr<DrawSystem> Draw;
	std::unique_ptr<RenderSystem> Render;
	std::unique_ptr<CommandLineSystem> CommandLine;


};