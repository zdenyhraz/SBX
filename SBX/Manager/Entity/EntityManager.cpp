#include "EntityManager.h"

EntityManager::EntityManager( std::shared_ptr<ComponentVectors> components ) :
	Manager( components ),
	m_EntityCnt( 0 ),
	m_MaxEntityId( 0 )
{

}

void EntityManager::CreateEntity( EntityInfoComponent::EntityType type )
{
	std::lock_guard<std::mutex> lock( m_mutex );
	m_Components->EntityInfos.Emplace( m_MaxEntityId, EntityInfoComponent( m_MaxEntityId, type ) );
	m_Components->Positions.Emplace( m_MaxEntityId, PositionComponent() );
	m_Components->Velocities.Emplace( m_MaxEntityId, VelocityComponent() );
	m_Components->Accelerations.Emplace( m_MaxEntityId, AccelerationComponent() );
	m_Components->Models.Emplace( m_MaxEntityId, ModelComponent() );

	m_MaxEntityId++;
	m_EntityCnt++;
}

void EntityManager::DeleteEntity( int id )
{
	std::lock_guard<std::mutex> lock( m_mutex );
	m_Components->Erase( id );

	m_EntityCnt--;
}