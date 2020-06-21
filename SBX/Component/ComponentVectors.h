#pragma once
#include "Stdafx.h"
#include "ComponentVector.h"
#include "EntityInfoComponent.h"
#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "AccelerationComponent.h"
#include "ModelComponent.h"
#include "TimeComponent.h"

class ComponentVectors
{
public:
	ComponentVector<EntityInfoComponent> EntityInfos;
	ComponentVector<PositionComponent> Positions;
	ComponentVector<VelocityComponent> Velocities;
	ComponentVector<AccelerationComponent> Accelerations;
	ComponentVector<ModelComponent> Models;
	TimeComponent Time;

private:
};