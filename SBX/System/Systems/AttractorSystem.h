#pragma once
#include "System/System.h"

class AttractorSystem : public System
{
public:

	AttractorSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick( float dt ) override;
};
