#pragma once
#include "ComponentVector.h"
#include "Time/TimeComponent.h"
#include "Map/MapComponent.h"
#include "Entity/EntityInfoComponent.h"
#include "Movement/PositionComponent.h"
#include "Movement/VelocityComponent.h"
#include "Movement/AccelerationComponent.h"
#include "Model/ModelComponent.h"
#include "Agent/AvoidanceAgentComponent.h"
#include "Agent/SeekingAgentComponent.h"
#include "Agent/SwarmAgentComponent.h"
#include "Agent/NomNomAgentComponent.h"


struct ComponentVectors
{
	TimeComponent Time;
	MapComponent Map;
	ComponentVector<EntityInfoComponent> EntityInfos;
	ComponentVector<PositionComponent> Positions;
	ComponentVector<VelocityComponent> Velocities;
	ComponentVector<AccelerationComponent> Accelerations;
	ComponentVector<ModelComponent> Models;
	ComponentVector<AvoidanceAgentComponent> AvoidanceAgents;
	ComponentVector<SeekingAgentComponent> SeekingAgents;
	ComponentVector<SwarmAgentComponent> SwarmAgents;
	ComponentVector<NomNomAgentComponent> NomNomAgents;

};