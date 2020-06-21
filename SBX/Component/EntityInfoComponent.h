#pragma once
#include "Stdafx.h"
#include "Component.h"

class EntityInfoComponent : public Component
{
public:
	enum EntityType { Entity };

	EntityInfoComponent( int id, bool alive = true, EntityType type = Entity, bool drawable = true ):
		Id( id ),
		Alive( alive ),
		Type( type ),
		Drawable( drawable ),
		Name( "Entity" + std::to_string( id ) )
	{

	}

	int Id;
	bool Alive;
	EntityType Type;
	bool Drawable;
	std::string Name;
private:
};