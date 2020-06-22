#include "SystemManager.h"
#include "System/SystemVector.h"

SystemManager::SystemManager( std::shared_ptr<SystemVector> systems ) :
	m_Systems( systems )
{

}

void SystemManager::Run()
{
	m_Systems->Run();
}

void SystemManager::End()
{
	m_Systems->End();
}