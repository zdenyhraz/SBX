#pragma once
#include "Stdafx.h"
#include "ComponentVector.h"
#include "Component/Components/VelocityComponent.h"

class VelocityComponentVector : public ComponentVector
{
public:
	VelocityComponentVector()
	{
		Velocities.reserve( 1000 );
	}

	std::unordered_map<int, VelocityComponent> Velocities;

private:

};