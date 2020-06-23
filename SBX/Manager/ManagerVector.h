#pragma once
#include "Entity/EntityManager.h"
#include "Time/TimeManager.h"

class ManagerVector
{
public:
	ManagerVector( std::shared_ptr<ComponentVectors> components );

	std::shared_ptr<EntityManager> m_EntityManager;
	std::shared_ptr<TimeManager> m_TimeManager;

private:
};

