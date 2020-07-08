#pragma once
#include "System/System.h"

class TestSystem : public System
{
public:

	TestSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
};
