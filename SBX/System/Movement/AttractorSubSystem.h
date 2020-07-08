#pragma once
#include "System/SubSystem.h"

class AttractorSubSystem : public SubSystem
{
public:

	AttractorSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
};
