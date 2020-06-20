#pragma once
#include "Stdafx.h"
#include "System.h"
#include "VelocitySystem.h"
#include "DrawSystem.h"
#include "RenderSystem.h"

class SystemVector
{
public:
	SystemVector( std::shared_ptr<ComponentVectors> components )
	{
		Velocity = std::make_unique<VelocitySystem>( components );
		Draw = std::make_unique<DrawSystem>( components );
		Render = std::make_unique<RenderSystem>( components );
	}

private:
	std::unique_ptr<VelocitySystem> Velocity;
	std::unique_ptr<DrawSystem> Draw;
	std::unique_ptr<RenderSystem> Render;

};