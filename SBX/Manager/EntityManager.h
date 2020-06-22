#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"

class EntityManager
{
public:
	EntityManager( std::shared_ptr<ComponentVectors> components );

	void CreateEntity( EntityInfoComponent::EntityType type = EntityInfoComponent::EntityType::Entity );

	void DeleteEntity( int id );

private:
	std::shared_ptr<ComponentVectors> m_Components;
	std::mutex m_mutex;
	int m_EntityCnt;
	int m_MaxEntityId;
};