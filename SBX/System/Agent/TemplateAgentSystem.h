#pragma once
#include "System/Agent/AgentSubSystem.h"

class TemplateAgentSystem : public AgentSubSystem
{
public:

	TemplateAgentSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:

};
