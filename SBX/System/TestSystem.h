#pragma once
#include "Stdafx.h"
#include "System.h"

class TestSystem : public System
{
public:

	TestSystem( std::shared_ptr<ComponentVectors> components );

	void Tick() override;

private:
};
