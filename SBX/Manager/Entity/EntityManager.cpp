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
	m_Components->EntityInfos.Data.emplace( std::pair<int, EntityInfoComponent>( m_MaxEntityId, EntityInfoComponent( m_MaxEntityId, type ) ) );
	m_Components->Positions.Data.emplace( std::pair<int, PositionComponent>( m_MaxEntityId, PositionComponent() ) );
	m_Components->Velocities.Data.emplace( std::pair<int, VelocityComponent>( m_MaxEntityId, VelocityComponent() ) );
	m_Components->Accelerations.Data.emplace( std::pair<int, AccelerationComponent>( m_MaxEntityId, AccelerationComponent() ) );
	m_Components->Models.Data.emplace( std::pair<int, ModelComponent>( m_MaxEntityId, ModelComponent() ) );
	m_Components->SwarmAgents.Data.emplace( std::pair<int, SwarmAgentComponent>( m_MaxEntityId, SwarmAgentComponent() ) );
	m_Components->NomNomAgents.Data.emplace( std::pair<int, NomNomAgentComponent>( m_MaxEntityId, NomNomAgentComponent() ) );

	m_MaxEntityId++;
	m_EntityCnt++;
}

void EntityManager::DeleteEntity( int id )
{
	std::lock_guard<std::mutex> lock( m_mutex );
	m_Components->EntityInfos.Data.erase( id );
	m_Components->Positions.Data.erase( id );
	m_Components->Velocities.Data.erase( id );
	m_Components->Accelerations.Data.erase( id );
	m_Components->Models.Data.erase( id );
	m_Components->SwarmAgents.Data.erase( id );
	m_Components->NomNomAgents.Data.erase( id );

	m_EntityCnt--;
}