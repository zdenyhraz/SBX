#pragma once
#include "Managers/EntityManager.h"
#include "Managers/EventManager.h"
#include "Managers/TimeManager.h"

class ManagerVector
{
public:
	ManagerVector( std::shared_ptr<ComponentVectors> components );

	std::shared_ptr<EntityManager> m_EntityManager;
	std::shared_ptr<EventManager> m_EventManager;
	std::shared_ptr<TimeManager> m_TimeManager;
};

