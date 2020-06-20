#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors/ComponentVectors.h"
#include "System/VelocitySystem.h"
#include "System/DrawSystem.h"

class SystemVector
{
public:
	SystemVector( ComponentVectors &ComponentVectors ) : ComponentVectors( ComponentVectors )
	{
		Velocity = std::make_unique<VelocitySystem>( ComponentVectors );
		Draw = std::make_unique<DrawSystem>( ComponentVectors );
	}


private:
	ComponentVectors &ComponentVectors;
	std::unique_ptr<VelocitySystem> Velocity;
	std::unique_ptr<DrawSystem> Draw;

};