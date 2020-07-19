#pragma once
#include "System/System.h"

class HealthSystem : public System
{
public:

	HealthSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick(float dt) override;
};
