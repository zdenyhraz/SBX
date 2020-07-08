#include "EntityManager.h"

EntityManager::EntityManager( std::shared_ptr<PastFutureComponentVectors> components ) :
	Manager( components ),
	m_EntityCnt( 0 ),
	m_MaxEntityId( 0 )
{

}

void EntityManager::CreateEntity( EntityInfoComponent::EntityType type )
{
	std::lock_guard<std::mutex> lock( m_mutex );
	int entityId = m_MaxEntityId;
	m_Components->Past.EntityInfos.Add( entityId );
	m_Components->Past.Positions.Add( entityId );
	m_Components->Past.Velocities.Add( entityId );
	m_Components->Past.Accelerations.Add( entityId );
	m_Components->Past.Models.Add( entityId );
	m_Components->Past.Agents.Add( entityId );

	auto &ei = m_Components->Past.EntityInfos.Find( entityId );
	ei.Id = entityId;
	ei.Name = std::to_string( entityId );

	m_MaxEntityId++;
	m_EntityCnt++;
}

void EntityManager::DeleteEntity( int id )
{
	std::lock_guard<std::mutex> lock( m_mutex );
	m_Components->Past.EraseEntity( id );

	m_EntityCnt--;
}