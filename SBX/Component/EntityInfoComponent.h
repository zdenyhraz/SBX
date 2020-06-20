#pragma once
#include "Stdafx.h"
#include "Component.h"

class EntityInfoComponent : public Component
{
public:
	enum EntityType { Entity };

	EntityInfoComponent( int id, bool alive = true, EntityType type = Entity ):
		Id( id ),
		Alive( alive ),
		Type( type )
	{

	}

	int Id;
	bool Alive;
	EntityType Type;
private:
};