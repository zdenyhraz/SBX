#pragma once
#include "Manager/Manager.h"
#include "Component/Event/EventComponent.h"

class EventManager : public Manager
{
public:
	EventManager( std::shared_ptr<ComponentVectors> components );

	void ProcessEvents()
	{
		for ( auto &event : m_Components->Events )
		{
			HandleEvent( event );
		}

		m_Components->Events.clear();
	}

	void AddEvent()
	{
		m_Components->Events.push_back( EventComponent() );
	}

private:
	void HandleEvent( const EventComponent &event )
	{

	}
};