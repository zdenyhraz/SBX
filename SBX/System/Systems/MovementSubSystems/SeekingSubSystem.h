#pragma once
#include "System/SubSystem.h"

class SeekingSubSystem : public SubSystem
{
public:

	SeekingSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:

};
