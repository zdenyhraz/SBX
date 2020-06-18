#pragma once
#include "Stdafx.h"
#include "EntityInfoComponentVector.h"
#include "PositionComponentVector.h"
#include "VelocityComponentVector.h"

class ComponentVectors
{
	EntityInfoComponentVector EntityInfos;
	PositionComponentVector Positions;
	VelocityComponentVector Velocities;
};