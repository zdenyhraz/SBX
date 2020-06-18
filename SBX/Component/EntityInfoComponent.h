#pragma once
#include "Stdafx.h"
#include "Component.h"

class EntityInfo : public Component
{
public:
	enum EntityType { friendly, enemy };
	int Id;
	bool Alive;
	EntityType Type;
private:
};