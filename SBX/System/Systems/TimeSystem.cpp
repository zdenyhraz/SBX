#include "TimeSystem.h"

TimeSystem::TimeSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Time", true )
{
}

void TimeSystem::Tick()
{
	m_Managers->m_TimeManager->Advance();
	m_ConsoleTitle = "Time = " + std::to_string( m_Managers->m_TimeManager->GetTime() ) + ", TimeRate = " + std::to_string( m_Managers->m_TimeManager->GetTimeRate() ) + ", Delta = " + std::to_string( m_Managers->m_TimeManager->GetDelta() ) + ", Running = " + std::to_string( m_Managers->m_TimeManager->GetRunning() ) + ", TickId = " + std::to_string( m_Managers->m_TimeManager->GetTickId() );
	SetConsoleTitle( m_ConsoleTitle.c_str() );
	std::this_thread::sleep_until( m_Managers->m_TimeManager->GetTargetTickEnd() );
}