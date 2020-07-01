#pragma once
#include "System/Agent/AgentSubSystem.h"

class NomNomAgentSystem : public AgentSubSystem
{
public:

	NomNomAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
};
