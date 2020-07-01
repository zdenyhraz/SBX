#include "System/System.h"
#include "Utils/ThreadUtils.h"
#include "Utils/TimeUtils.h"
#include "Utils/MathUtils.h"

System::System( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, const std::string &name, int refreshRate ) :
	m_Components( components ),
	m_Managers( managers ),
	m_Name( name ),
	m_Enabled( true ),
	m_RefreshRate( refreshRate ),
	m_LogLoadPeriod( 15 * 1000000 )
{
	m_TargetTickDuration = ( long long )( 1. / m_RefreshRate * 1e6 );
	m_LastLogLoad = Utils::GetTimeNow();
}

void System::Run()
{
	LOG_DEBUG( "Running <{}> system on thread {} with => {} <= refresh rate", m_Name, Utils::ThisThreadId(), m_RefreshRate > 0 ? std::to_string( ( int )m_RefreshRate ) + " Hz" : "MAX" );
	m_Enabled = true;

	if ( m_RefreshRate > 0 )
	{
		while ( m_Enabled )
		{
			m_TickStart = Utils::GetTimeNow();
			m_TargetTickEnd = m_TickStart + std::chrono::microseconds( m_TargetTickDuration );
			Tick();
			m_TickEnd = Utils::GetTimeNow();

			m_TickDuration = Utils::GetDuration( m_TickStart, m_TickEnd );
			m_LoadPercent = ( int )( ( double )m_TickDuration / m_TargetTickDuration * 100 );

			if ( m_LoadPercent > 0 && ( Utils::GetDuration( m_LastLogLoad, m_TickEnd ) > m_LogLoadPeriod ) )
			{
				m_LastLogLoad = m_TickEnd;
				LOG_SUCC( "System <{}> thread load {}% ({} Hz)", m_Name, m_LoadPercent, ( int )m_RefreshRate );
			}

			if ( m_LoadPercent >= 100 )
			{
				continue;
			}

			std::this_thread::sleep_until( m_TargetTickEnd );
		}
	}
	else
	{
		while ( m_Enabled )
		{
			Tick();
		}
	}
}

void System::Kill()
{
	LOG_DEBUG( "Killing <{}> system", m_Name );
	m_Enabled = false;
}