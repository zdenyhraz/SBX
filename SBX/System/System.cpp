#include "System/System.h"
#include "Utils/ThreadUtils.h"
#include "Utils/TimeUtils.h"
#include "Utils/MathUtils.h"

System::System( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::string &&name, double refreshRate, bool logLoad ) :
	m_Components( components ),
	m_Managers( managers ),
	m_Name( std::move( name ) ),
	m_Enabled( true ),
	m_RefreshRate( refreshRate ),
	m_LogLoad( logLoad ),
	m_LogLoadPeriod( 10 )
{
	m_TargetTickDuration = ( long long )( 1. / m_RefreshRate * 1e6 );
	m_LastLogLoad = Utils::GetTimeNow();
}

void System::Run()
{
	LOG_DEBUG( "Running <{}> system on thread {} with {} Hz refresh rate", m_Name, Utils::ThisThreadId(), m_RefreshRate );
	m_Enabled = true;

	while ( m_Enabled )
	{
		m_TickStart = Utils::GetTimeNow();
		Tick();
		m_TickEnd = Utils::GetTimeNow();

		m_TickDuration = Utils::GetDuration( m_TickStart, m_TickEnd );

		if ( m_LogLoad && ( Utils::GetDuration( m_LastLogLoad, m_TickEnd ) > ( m_LogLoadPeriod * 1000000 ) ) )
		{
			m_LastLogLoad = m_TickEnd;
			LOG_DEBUG( "System <{}> thread load {}% ({} Hz)", m_Name, ( int )( ( double )m_TickDuration / m_TargetTickDuration * 100 ), m_RefreshRate );
		}

		std::this_thread::sleep_for( std::chrono::microseconds( std::max( m_TargetTickDuration - m_TickDuration, 0ll ) ) );
	}
}

void System::Kill()
{
	LOG_DEBUG( "Killing <{}> system", m_Name );
	m_Enabled = false;
}