#pragma once
#include "System/System.h"
#include "System/SubSystem.h"

class MovementSystem : public System
{
public:

	MovementSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
	std::vector<std::shared_ptr<SubSystem>> m_SubSystems;

};
