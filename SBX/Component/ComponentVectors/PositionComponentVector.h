#pragma once
#include "Stdafx.h"
#include "ComponentVector.h"
#include "Component/Components/PositionComponent.h"

class PositionComponentVector : public ComponentVector
{
public:
	std::unordered_map<int, PositionComponent> Positions;

private:
};