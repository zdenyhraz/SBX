#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"

class EntityManager
{
public:
	EntityManager( std::shared_ptr<ComponentVectors> components ):
		m_Components( components ),
		m_EntityCnt( 0 ),
		m_MaxEntityId( 0 )
	{

	}

	void CreateEntity( bool alive = true, EntityInfoComponent::EntityType type = EntityInfoComponent::EntityType::Entity )
	{
		m_Components->EntityInfos.Data.emplace( std::pair<int, EntityInfoComponent>( m_MaxEntityId, EntityInfoComponent( m_MaxEntityId, alive, type ) ) );
		m_Components->Positions.Data.emplace( std::pair<int, PositionComponent>( m_MaxEntityId, PositionComponent() ) );
		m_Components->Velocities.Data.emplace( std::pair<int, VelocityComponent>( m_MaxEntityId, VelocityComponent() ) );
		m_Components->Accelerations.Data.emplace( std::pair<int, AccelerationComponent>( m_MaxEntityId, AccelerationComponent() ) );
		m_Components->Models.Data.emplace( std::pair<int, ModelComponent>( m_MaxEntityId, ModelComponent() ) );

		std::lock_guard<std::mutex> lock( m_mutex );
		m_MaxEntityId++;
		m_EntityCnt++;
	}

	void DeleteEntity( int id )
	{
		std::lock_guard<std::mutex> lock( m_mutex );
		m_EntityCnt--;
	}

private:
	std::shared_ptr<ComponentVectors> m_Components;
	std::mutex m_mutex;
	int m_EntityCnt;
	int m_MaxEntityId;
};