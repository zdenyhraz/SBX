#include "HealthSubSystem.h"

HealthSubSystem::HealthSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	SubSystem( components, managers )
{

}

void HealthSubSystem::Tick()
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