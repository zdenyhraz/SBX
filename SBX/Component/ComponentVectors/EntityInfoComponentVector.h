#pragma once
#include "Stdafx.h"
#include "ComponentVector.h"
#include "Component/Components/EntityInfoComponent.h"

class EntityInfoComponentVector : public ComponentVector
{
public:
	EntityInfoComponentVector()
	{
		EntityInfos.reserve( 1000 );
	}

	std::unordered_map<int, EntityInfoComponent> EntityInfos;

private:

};