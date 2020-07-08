#pragma once
#include "System/System.h"

class LogicSystem : public System
{
public:

	LogicSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
};
