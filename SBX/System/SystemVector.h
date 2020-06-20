#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors/ComponentVectors.h"
#include "VelocitySystem.h"
#include "DrawSystem.h"
#include "RenderSystem.h"

class SystemVector
{
public:
	SystemVector( std::shared_ptr<ComponentVectors> ComponentVectors ) : ComponentVectors( ComponentVectors )
	{
		Velocity = std::make_unique<VelocitySystem>( ComponentVectors );
		Draw = std::make_unique<DrawSystem>( ComponentVectors );
		Render = std::make_unique<RenderSystem>( ComponentVectors );
	}


private:
	std::shared_ptr<ComponentVectors> ComponentVectors;
	std::unique_ptr<VelocitySystem> Velocity;
	std::unique_ptr<DrawSystem> Draw;
	std::unique_ptr<RenderSystem> Render;

};