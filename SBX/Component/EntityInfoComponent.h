#pragma once
#include "Stdafx.h"
#include "Component.h"

class EntityInfoComponent : public Component
{
public:
	enum EntityType { Entity };

	EntityInfoComponent( int id, bool alive = true, EntityType type = Entity ):
		m_Id( id ),
		m_Alive( alive ),
		m_Type( type )
	{

	}

	int m_Id;
	bool m_Alive;
	EntityType m_Type;
private:
};