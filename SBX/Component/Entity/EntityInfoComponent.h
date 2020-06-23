#pragma once
#include "Component/Component.h"

struct EntityInfoComponent : Component
{
	enum EntityType { Entity };

	EntityInfoComponent( int id, EntityType type = Entity ):
		Id( id ),
		Type( type ),
		Name( "Entity" ),
		HP( 100 )
	{
		if ( Name == "Entity" )
			Name = "Entity" + std::to_string( id );
	}

	int Id;
	EntityType Type;
	std::string Name;
	int HP;
};