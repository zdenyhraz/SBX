#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"

class EntityManager
{
public:
	EntityManager( std::shared_ptr<ComponentVectors> components ) : Components( components )
	{

	}

	void CreateEntity( bool alive = true, EntityInfoComponent::EntityType type = EntityInfoComponent::EntityType::Entity )
	{
		Components->EntityInfos.Data.emplace( std::pair<int, EntityInfoComponent>( MaxEntityId, EntityInfoComponent( MaxEntityId, alive, type ) ) );
		Components->Positions.Data.emplace( std::pair<int, PositionComponent>( MaxEntityId, PositionComponent() ) );
		Components->Velocities.Data.emplace( std::pair<int, VelocityComponent>( MaxEntityId, VelocityComponent() ) );

		MaxEntityId++;
		EntityCnt++;
	}

	void DeleteEntity( int id )
	{

		EntityCnt--;
	}

private:
	std::shared_ptr<ComponentVectors> Components;
	int EntityCnt = 0;
	int MaxEntityId = 0;
};