#pragma once
#include "Manager/Manager.h"
#include "Component/Event/EventComponent.h"

class EventManager : public Manager
{
public:
	EventManager( std::shared_ptr<ComponentVectors> components );

	void ProcessEvents()
	{
		std::lock_guard<std::mutex> lock( m_mutex );

		for ( auto &event : m_Components->Events )
		{
			HandleEvent( event );
		}

		m_Components->Events.clear();
	}

	void AddEvent()
	{
		std::lock_guard<std::mutex> lock( m_mutex );
	}

private:
	void HandleEvent( const EventComponent &event )
	{

	}
};