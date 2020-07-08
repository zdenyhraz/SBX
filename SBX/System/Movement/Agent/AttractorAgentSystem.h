#pragma once
#include "System/SubSystem.h"

class AttractorAgentSystem : public SubSystem
{
public:

	AttractorAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
};
