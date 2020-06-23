#include "TemplateAgentSystem.h"

TemplateAgentSystem::TemplateAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	m_Components( components ),
	m_Managers( managers )
{

}

void TemplateAgentSystem::Tick()
{

}
