#pragma once
#include "System/Agent/AgentSubSystem.h"

class AttractorAgentSystem : public AgentSubSystem
{
public:

	AttractorAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
};
