#include "EventSubSystem.h"

EventSubSystem::EventSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	SubSystem( components, managers )
{

}

void EventSubSystem::Tick()
{
	m_Managers->m_EventManager->ProcessEvents();
}
