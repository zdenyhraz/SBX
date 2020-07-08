#pragma once
#include "System/System.h"

class TemplateSystem : public System
{
public:

	TemplateSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
};
