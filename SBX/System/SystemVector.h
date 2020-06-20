#pragma once
#include "Stdafx.h"
#include "System.h"
#include "PositionSystem.h"
#include "VelocitySystem.h"
#include "AccelerationSystem.h"
#include "DrawSystem.h"
#include "RenderSystem.h"

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
	}

private:
	std::unique_ptr<PositionSystem> Position;
	std::unique_ptr<VelocitySystem> Velocity;
	std::unique_ptr<AccelerationSystem> Acceleration;
	std::unique_ptr<DrawSystem> Draw;
	std::unique_ptr<RenderSystem> Render;

};