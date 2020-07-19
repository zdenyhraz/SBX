#pragma once
#include "System/System.h"

class SeekingSystem : public System
{
public:

	SeekingSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick(float dt) override;

private:

};
