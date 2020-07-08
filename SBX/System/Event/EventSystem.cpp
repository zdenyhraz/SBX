#include "EventSystem.h"

EventSystem::EventSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Event" )
{

}

void EventSystem::Tick()
{
	m_Managers->m_EventManager->ProcessEvents();
}