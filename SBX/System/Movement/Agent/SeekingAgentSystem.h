#pragma once
#include "System/SubSystem.h"

class SeekingAgentSystem : public SubSystem
{
public:

	SeekingAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:

};
