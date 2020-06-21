#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"

class EntityManager
{
public:
	EntityManager( std::shared_ptr<ComponentVectors> components ): m_Components( components )
	{

	}

	void CreateEntity( bool alive = true, EntityInfoComponent::EntityType type = EntityInfoComponent::EntityType::Entity )
	{
		m_Components->EntityInfos.Data.emplace( std::pair<int, EntityInfoComponent>( m_MaxEntityId, EntityInfoComponent( m_MaxEntityId, alive, type ) ) );
		m_Components->Positions.Data.emplace( std::pair<int, PositionComponent>( m_MaxEntityId, PositionComponent() ) );
		m_Components->Velocities.Data.emplace( std::pair<int, VelocityComponent>( m_MaxEntityId, VelocityComponent() ) );
		m_Components->Accelerations.Data.emplace( std::pair<int, AccelerationComponent>( m_MaxEntityId, AccelerationComponent() ) );
		m_Components->Models.Data.emplace( std::pair<int, ModelComponent>( m_MaxEntityId, ModelComponent() ) );

		m_MaxEntityId++;
		m_EntityCnt++;
	}

	void DeleteEntity( int id )
	{

		m_EntityCnt--;
	}

private:
	std::shared_ptr<ComponentVectors> m_Components;
	int m_EntityCnt = 0;
	int m_MaxEntityId = 0;
};