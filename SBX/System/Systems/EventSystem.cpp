#include "EventSystem.h"

EventSystem::EventSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers )
{

}

void EventSystem::Tick(float dt)
{
	m_Managers->m_EventManager->ProcessEvents();
}
