#include "ManagerVector.h"

ManagerVector::ManagerVector( std::shared_ptr<ComponentVectors> components )
{
	m_EntityManager = std::make_shared<EntityManager>( components );
}

