#pragma once
#include "System/System.h"

class EventSystem : public System
{
public:

	EventSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick(float dt) override;
};

