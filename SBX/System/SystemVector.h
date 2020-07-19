#pragma once
#include "Stdafx.h"
#include "Systems/AttractorSystem.h"
#include "Systems/AvoidanceSystem.h"
#include "Systems/CommandLineSystem.h"
#include "Systems/DrawSystem.h"
#include "Systems/EventSystem.h"
#include "Systems/HealthSystem.h"
#include "Systems/LogicSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/SeekingSystem.h"
#include "Systems/SwarmSystem.h"
#include "Systems/TimeSystem.h"

struct SystemVector
{
	SystemVector( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers )
	{
		Attractor = std::make_unique<AttractorSystem>( components, managers );
		Avoidance = std::make_unique<AvoidanceSystem>( components, managers );
		CommandLine = std::make_unique<CommandLineSystem>( components, managers );
		Draw = std::make_unique<DrawSystem>( components, managers );
		Event = std::make_unique<EventSystem>( components, managers );
		Health = std::make_unique<HealthSystem>( components, managers );
		Logic = std::make_unique<LogicSystem>( components, managers );
		Movement = std::make_unique<MovementSystem>( components, managers );
		Seeking = std::make_unique<SeekingSystem>( components, managers );
		Swarm = std::make_unique<SwarmSystem>( components, managers );
		Time = std::make_unique<TimeSystem>( components, managers );
	}

	std::unique_ptr<AttractorSystem> Attractor;
	std::unique_ptr<AvoidanceSystem> Avoidance;
	std::unique_ptr<CommandLineSystem>CommandLine;
	std::unique_ptr<DrawSystem>Draw;
	std::unique_ptr<EventSystem>Event;
	std::unique_ptr<HealthSystem>Health;
	std::unique_ptr<LogicSystem>Logic;
	std::unique_ptr<MovementSystem>Movement;
	std::unique_ptr<SeekingSystem>Seeking;
	std::unique_ptr<SwarmSystem>Swarm;
	std::unique_ptr<TimeSystem>Time;
};