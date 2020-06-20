#pragma once
#include "Stdafx.h"
#include "ComponentVector.h"
#include "EntityInfoComponent.h"
#include "PositionComponent.h"
#include "VelocityComponent.h"

class ComponentVectors
{
public:
	ComponentVector<EntityInfoComponent> EntityInfos;
	ComponentVector<PositionComponent> Positions;
	ComponentVector<VelocityComponent> Velocities;

private:
};