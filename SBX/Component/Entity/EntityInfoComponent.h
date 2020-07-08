#pragma once
#include "Component/Component.h"

struct EntityInfoComponent : Component
{
	enum EntityType { Entity };

	EntityInfoComponent():
		Id( 0 ),
		Type( Entity ),
		Name( "" ),
		HP( 100 )
	{

	}

	int Id;
	EntityType Type;
	std::string Name;
	int HP;
};