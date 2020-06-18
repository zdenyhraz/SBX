#pragma once
#include "Stdafx.h"
#include "ComponentVector.h"
#include "Component/Components/EntityInfoComponent.h"

class EntityInfoComponentVector : public ComponentVector
{
public:
	std::unordered_map<int, EntityInfoComponent> EntityInfos;

private:
};