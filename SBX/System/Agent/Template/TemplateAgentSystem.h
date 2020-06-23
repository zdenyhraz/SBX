#pragma once
#include "System/System.h"

class TemplateAgentSystem
{
public:

	TemplateAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick();

private:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
};
