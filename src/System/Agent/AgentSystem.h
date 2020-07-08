#pragma once
#include "System/System.h"
#include "System/Agent/AgentSubSystem.h"

class AgentSystem : public System
{
public:

	AgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
	std::vector<std::shared_ptr<AgentSubSystem>> m_AgentSubSystems;
};
