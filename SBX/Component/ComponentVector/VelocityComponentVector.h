#pragma once
#include "Stdafx.h"
#include "ComponentVector.h"
#include "Component/Component/VelocityComponent.h"

class VelocityComponentVector : public ComponentVector
{
public:
	std::unordered_map<int, VelocityComponent> Velocities;

private:
};