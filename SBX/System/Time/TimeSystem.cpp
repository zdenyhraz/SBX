#include "TimeSystem.h"

TimeSystem::TimeSystem( std::shared_ptr<ComponentVectors> components ) :
	System( components, "Time" )
{

}

void TimeSystem::Tick()
{
	m_Components->Time.Advance();
	m_ConsoleTitle = "Time = " + std::to_string( m_Components->Time.GetTime() ) + ", TimeRate = " + std::to_string( m_Components->Time.GetTimeRate() ) + ", Delta = " + std::to_string( m_Components->Time.GetDelta() ) + ", Running = " + std::to_string( m_Components->Time.GetRunning() );
	SetConsoleTitle( m_ConsoleTitle.c_str() );
}