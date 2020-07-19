#include "HealthSystem.h"

HealthSystem::HealthSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers )
{

}

void HealthSystem::Tick(float dt)
{
	for ( auto &entity : m_Components->EntityInfos.GetContainer() )
	{
		int id = entity.first;

		if ( entity.second.Health <= 0 )
		{
			m_Managers->m_EntityManager->DeleteEntity( id );
		}
	}
}