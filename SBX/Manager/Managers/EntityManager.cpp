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
	int entityId = m_MaxEntityId;
	m_Components->EntityInfos.Add( entityId );
	m_Components->Positions.Add( entityId );
	m_Components->Velocities.Add( entityId );
	m_Components->Accelerations.Add( entityId );
	m_Components->Models.Add( entityId );
	m_Components->Agents.Add( entityId );

	auto &ei = m_Components->EntityInfos.Find( entityId );
	ei.Id = entityId;
	ei.Name = std::to_string( entityId );

	m_MaxEntityId++;
	m_EntityCnt++;
}

void EntityManager::DeleteEntity( int id )
{
	std::lock_guard<std::mutex> lock( m_mutex );
	m_Components->EraseEntity( id );

	m_EntityCnt--;
}