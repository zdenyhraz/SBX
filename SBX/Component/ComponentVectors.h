#pragma once
#include "ComponentVector.h"
#include "MapComponentVector.h"
#include "VecComponentVector.h"
#include "Time/TimeComponent.h"
#include "Map/MapComponent.h"
#include "Entity/EntityInfoComponent.h"
#include "Movement/PositionComponent.h"
#include "Movement/VelocityComponent.h"
#include "Movement/AccelerationComponent.h"
#include "Model/ModelComponent.h"
#include "Agent/AgentComponent.h"

struct ComponentVectors
{
	TimeComponent Time;
	MapComponent Map;
	MapComponentVector<int, EntityInfoComponent> EntityInfos;
	MapComponentVector<int, PositionComponent> Positions;
	MapComponentVector<int, VelocityComponent> Velocities;
	MapComponentVector<int, AccelerationComponent> Accelerations;
	MapComponentVector<int, ModelComponent> Models;
	MapComponentVector<int, AgentComponent> Agents;

	void Erase( int id )
	{
		EntityInfos.Erase( id );
		Positions.Erase( id );
		Velocities.Erase( id );
		Accelerations.Erase( id );
		Models.Erase( id );
		Agents.Erase( id );
	}

};