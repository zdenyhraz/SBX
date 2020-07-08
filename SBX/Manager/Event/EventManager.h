#pragma once
#include "Manager/Manager.h"
#include "Component/Event/EventComponent.h"

class EventManager : public Manager
{
public:
	EventManager( std::shared_ptr<PastFutureComponentVectors> components );

	void ProcessEvents()
	{
		for ( auto &event : m_Components->Past->Events )
		{
			HandleEvent( event );
		}

		m_Components->Past->Events.clear();
	}

	void AddEvent()
	{
		m_Components->Past->Events.push_back( EventComponent() );
	}

private:
	void HandleEvent( const EventComponent &event )
	{

	}
};