#pragma once
#include "Time/TimeComponent.h"
#include "Map/MapComponent.h"
#include "Event/EventComponent.h"
#include "Containers/MapComponentVector.h"
#include "Containers/VecComponentVector.h"
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
	std::vector<EventComponent> Events;
	MapComponentVector<int, EntityInfoComponent> EntityInfos;
	MapComponentVector<int, PositionComponent> Positions;
	MapComponentVector<int, VelocityComponent> Velocities;
	MapComponentVector<int, AccelerationComponent> Accelerations;
	MapComponentVector<int, ModelComponent> Models;
	MapComponentVector<int, AgentComponent> Agents;

	ComponentVectors()
	{
		Events.reserve( 20 );
	}

	void EraseEntity( int id )
	{
		EntityInfos.Remove( id );
		Positions.Remove( id );
		Velocities.Remove( id );
		Accelerations.Remove( id );
		Models.Remove( id );
		Agents.Remove( id );
	}
};