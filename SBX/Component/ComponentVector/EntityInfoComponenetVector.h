#pragma once
#include "Stdafx.h"
#include "ComponentVector.h"
#include "Component/Component/EntityInfoComponent.h"

class EntityInfoComponentVector : public ComponentVector
{
public:
	std::unordered_map<int, EntityInfo> EntityInfos;

private:
};