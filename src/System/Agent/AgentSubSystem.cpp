#include "AgentSubSystem.h"

AgentSubSystem::AgentSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ):
	m_Components( components ),
	m_Managers( managers )
{

}