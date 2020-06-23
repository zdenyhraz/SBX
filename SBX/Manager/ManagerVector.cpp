#include "ManagerVector.h"

ManagerVector::ManagerVector( std::shared_ptr<ComponentVectors> components )
{
	m_EntityManager = std::make_shared<EntityManager>( components );
	m_TimeManager = std::make_shared<TimeManager>( components );
}

