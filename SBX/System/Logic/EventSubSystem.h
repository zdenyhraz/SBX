#pragma once
#include "System/SubSystem.h"

class EventSubSystem : public SubSystem
{
public:

	EventSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;
};

