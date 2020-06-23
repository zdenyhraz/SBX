#include "TimeSystem.h"

TimeSystem::TimeSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Time" )
{

}

void TimeSystem::Tick()
{
	m_Components->Time.Advance();
	m_ConsoleTitle = "Time = " + std::to_string( m_Components->Time.Time ) + ", TimeRate = " + std::to_string( m_Components->Time.TimeRate ) + ", Delta = " + std::to_string( m_Components->Time.Delta ) + ", Running = " + std::to_string( m_Components->Time.Running );
	SetConsoleTitle( m_ConsoleTitle.c_str() );
}