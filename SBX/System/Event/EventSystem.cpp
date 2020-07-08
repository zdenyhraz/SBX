#include "EventSystem.h"

EventSystem::EventSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Event" )
{

}

void EventSystem::Tick()
{
	for ( auto &event : m_Components->Events )
	{

	}
}