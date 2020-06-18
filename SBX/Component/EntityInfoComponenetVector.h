#pragma once
#include "Stdafx.h"
#include "ComponentVector.h"
#include "EntityInfoComponent.h"

class EntityInfoComponentVector : public ComponentVector
{
public:
	std::unordered_map<int, EntityInfo> EntityInfos;

private:
};