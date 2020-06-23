#pragma once
#include "Stdafx.h"
#include "Manager/Manager.h"

class EntityManager: public Manager
{
public:
	EntityManager( std::shared_ptr<ComponentVectors> components );

	void CreateEntity( EntityInfoComponent::EntityType type = EntityInfoComponent::EntityType::Entity );

	void DeleteEntity( int id );

private:
	int m_EntityCnt;
	int m_MaxEntityId;
};