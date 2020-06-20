#pragma once
#include "Stdafx.h"
#include "Component/ComponentVector.h"
#include "EntityInfoComponent.h"

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