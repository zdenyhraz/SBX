#pragma once
#include "Entity/EntityManager.h"
#include "Event/EventManager.h"

class ManagerVector
{
public:
	ManagerVector( std::shared_ptr<PastFutureComponentVectors> components );

	std::shared_ptr<EntityManager> m_EntityManager;
	std::shared_ptr<EventManager> m_EventManager;

private:
};

