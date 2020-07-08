#pragma once
#include "System/System.h"
#include "System/SubSystem.h"

class MovementSystem : public System
{
public:

	MovementSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;
};
