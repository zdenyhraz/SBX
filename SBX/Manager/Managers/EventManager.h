#pragma once
#include "Manager/Manager.h"
#include "Component/Components/EventComponent.h"

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

	void AddEvent( const EventComponent &event )
	{
		std::lock_guard<std::mutex> lock( m_mutex );
		m_Components->Events.push_back( event );
	}

private:
	void HandleEvent( const EventComponent &event )
	{

	}
};