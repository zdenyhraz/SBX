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

		m_MaxEntityId.fetch_add( 1, std::memory_order_relaxed );
		m_EntityCnt.fetch_add( 1, std::memory_order_relaxed );
	}

	void DeleteEntity( int id )
	{
		m_EntityCnt.fetch_sub( 1, std::memory_order_relaxed );
	}

private:
	std::shared_ptr<ComponentVectors> m_Components;
	std::atomic<int> m_EntityCnt = 0;
	std::atomic<int> m_MaxEntityId = 0;
};