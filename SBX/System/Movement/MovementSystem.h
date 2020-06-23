#pragma once
#include "Stdafx.h"
#include "System/System.h"

class MovementSystem : public System
{
public:

	MovementSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
};
