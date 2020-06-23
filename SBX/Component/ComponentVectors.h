#pragma once
#include "ComponentVector.h"
#include "Time/TimeComponent.h"
#include "Entity/EntityInfoComponent.h"
#include "Movement/PositionComponent.h"
#include "Movement/VelocityComponent.h"
#include "Movement/AccelerationComponent.h"
#include "Model/ModelComponent.h"
#include "Agent/AvoidanceAgentComponent.h"
#include "Agent/SeekingAgentComponent.h"

struct ComponentVectors
{
	TimeComponent Time;
	ComponentVector<EntityInfoComponent> EntityInfos;
	ComponentVector<PositionComponent> Positions;
	ComponentVector<VelocityComponent> Velocities;
	ComponentVector<AccelerationComponent> Accelerations;
	ComponentVector<ModelComponent> Models;
	ComponentVector<AvoidanceAgentComponent> AvoidanceAgents;
	ComponentVector<SeekingAgentComponent> SeekingAgents;
};