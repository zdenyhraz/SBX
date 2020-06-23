#pragma once
#include "Stdafx.h"
#include "System/System.h"

class TestSystem : public System
{
public:

	TestSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
};
