#pragma once
#include "System/System.h"

class RenderSystem : public System
{
public:

	RenderSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
};
