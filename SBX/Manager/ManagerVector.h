#pragma once
#include "EntityManager.h"

class ManagerVector
{
public:
	ManagerVector( std::shared_ptr<ComponentVectors> components );

	std::shared_ptr<EntityManager> m_EntityManager;

private:
};

