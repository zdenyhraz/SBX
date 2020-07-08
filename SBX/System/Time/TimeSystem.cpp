#include "TimeSystem.h"

TimeSystem::TimeSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Time", true )
{
}

void TimeSystem::Tick()
{
	m_Components->Past->Time.Advance();
	m_ConsoleTitle = "Time = " + std::to_string( m_Components->Past->Time.GetTime() ) + ", TimeRate = " + std::to_string( m_Components->Past->Time.GetTimeRate() ) + ", Delta = " + std::to_string( m_Components->Past->Time.GetDelta() ) + ", Running = " + std::to_string( m_Components->Past->Time.GetRunning() ) + ", TickId = " + std::to_string( m_Components->Past->Time.GetTickId() );
	SetConsoleTitle( m_ConsoleTitle.c_str() );
	std::this_thread::sleep_until( m_Components->Past->Time.GetTargetTickEnd() );
}
