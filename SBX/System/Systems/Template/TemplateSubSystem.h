#pragma once
#include "System/SubSystem.h"

class TemplateSubSystem : public SubSystem
{
public:

	TemplateSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;
};
