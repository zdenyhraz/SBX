#pragma once
#include "System/System.h"

class AgentSystem : public System
{
public:

	AgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
};
