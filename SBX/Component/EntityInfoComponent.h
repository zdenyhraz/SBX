#pragma once
#include "Stdafx.h"
#include "Component.h"

class EntityInfoComponent : public Component
{
public:
	enum EntityType { Entity };

	EntityInfoComponent( int id, bool alive = true, EntityType type = Entity, bool drawable = true ):
		m_Id( id ),
		m_Alive( alive ),
		m_Type( type ),
		m_Drawable( drawable ),
		m_Name( "Entity" + std::to_string( id ) )
	{

	}

	int m_Id;
	bool m_Alive;
	EntityType m_Type;
	bool m_Drawable;
	std::string m_Name;
private:
};