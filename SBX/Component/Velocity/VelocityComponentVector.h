#pragma once
#include "Stdafx.h"
#include "Component/ComponentVector.h"
#include "VelocityComponent.h"

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