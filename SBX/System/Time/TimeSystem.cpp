#include "TimeSystem.h"

TimeSystem::TimeSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Time", true )
{
}

void TimeSystem::Tick()
{
	m_Components->Time.Advance();
	m_ConsoleTitle = "Time = " + std::to_string( m_Components->Time.GetTime() ) + ", TimeRate = " + std::to_string( m_Components->Time.GetTimeRate() ) + ", Delta = " + std::to_string( m_Components->Time.GetDelta() ) + ", Running = " + std::to_string( m_Components->Time.GetRunning() ) + ", TickId = " + std::to_string( m_Components->Time.GetTickId() );
	SetConsoleTitle( m_ConsoleTitle.c_str() );
	m_Components->SystemsReady.ClearStatus();
	//WaitForAllSystems();
	std::this_thread::sleep_until( m_Components->Time.GetTargetTickEnd() );
}

void TimeSystem::WaitForAllSystems()
{
	m_SystemsReady = false;
	while ( !m_SystemsReady )
	{
		m_SystemsReady = m_Components->SystemsReady.Ready();
	}
}