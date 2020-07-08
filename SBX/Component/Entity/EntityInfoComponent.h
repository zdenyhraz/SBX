#pragma once
#include "Component/Component.h"

struct EntityInfoComponent : Component
{
	enum EntityType { Entity };

	EntityInfoComponent( int id, EntityType type = Entity ):
		Id( id ),
		Type( type ),
		Name( std::to_string( id ) ),
		HP( 100 )
	{

	}

	int Id;
	EntityType Type;
	std::string Name;
	int HP;
};