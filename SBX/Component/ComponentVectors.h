#pragma once
#include "Containers/MapComponentVector.h"
#include "Containers/VecComponentVector.h"
#include "Components/TimeComponent.h"
#include "Components/MapComponent.h"
#include "Components/EventComponent.h"
#include "Components/EntityInfoComponent.h"
#include "Components/PositionComponent.h"
#include "Components/VelocityComponent.h"
#include "Components/AccelerationComponent.h"
#include "Components/ModelComponent.h"
#include "Components/AgentComponent.h"

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