#pragma once
#include "System/Agent/AgentSubSystem.h"

class SeekingAgentSystem : public AgentSubSystem
{
public:

	SeekingAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:

};
