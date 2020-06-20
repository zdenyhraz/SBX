#pragma once
#include "Stdafx.h"
#include "EntityInfo/EntityInfoComponentVector.h"
#include "Position/PositionComponentVector.h"
#include "Velocity/VelocityComponentVector.h"

class ComponentVectors
{
	EntityInfoComponentVector EntityInfos;
	PositionComponentVector Positions;
	VelocityComponentVector Velocities;
};