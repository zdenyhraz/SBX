#pragma once
#include "System/SubSystem.h"

class HealthSubSystem : public SubSystem
{
public:

	HealthSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;
};
