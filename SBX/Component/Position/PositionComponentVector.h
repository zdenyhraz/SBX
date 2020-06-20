#pragma once
#include "Stdafx.h"
#include "Component/ComponentVector.h"
#include "PositionComponent.h"

class PositionComponentVector : public ComponentVector
{
public:
	PositionComponentVector()
	{
		Positions.reserve( 1000 );
	}

	std::unordered_map<int, PositionComponent> Positions;

private:

};