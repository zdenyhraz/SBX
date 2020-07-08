#pragma once
#include "System/SubSystem.h"

class SeekingAgentSystem : public SubSystem
{
public:

	SeekingAgentSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:

};