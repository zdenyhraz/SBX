#pragma once
#include "Stdafx.h"
#include "System.h"

class MovementSystem : public System
{
public:

	MovementSystem( std::shared_ptr<ComponentVectors> components );

	void Tick() override;

private:
};
