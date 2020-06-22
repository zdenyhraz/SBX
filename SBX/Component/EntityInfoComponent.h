#pragma once
#include "Stdafx.h"
#include "Component.h"

class EntityInfoComponent : public Component
{
public:
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
private:
};