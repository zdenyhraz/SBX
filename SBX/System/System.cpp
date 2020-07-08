#include "System/System.h"
#include "Utils/ThreadUtils.h"
#include "Utils/TimeUtils.h"
#include "Utils/MathUtils.h"

System::System( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers, const std::string &name, bool async ) :
	m_Components( components ),
	m_Managers( managers ),
	m_Name( name ),
	m_Enabled( true ),
	m_LogLoadPeriod( 15 * 1000 ),
	m_Async( async )
{
	m_LastLogLoad = Utils::GetTimeNow();
}

void System::Run()
{
	LOG_DEBUG( "Running <{}> system on thread {}", m_Name, Utils::ThisThreadId() );
	m_Enabled = true;
	m_LastTargetTickEnd = Utils::GetTimeNow();

	if ( m_Async )
	{
		while ( m_Enabled )
		{
			Tick();
		}
	}
	else
	{
		while ( m_Enabled )
		{
			if ( m_LastTargetTickEnd < m_Components->Past.Time.GetTargetTickEnd() )
			{
				m_TickStart = Utils::GetTimeNow();
				Tick();
				m_TickEnd = Utils::GetTimeNow();

				m_LastTargetTickEnd = m_Components->Past.Time.GetTargetTickEnd();
				m_TickDuration = Utils::GetDuration( m_TickStart, m_TickEnd );
				m_LoadPercent = ( int )( ( double )m_TickDuration / TimeComponent::TargetTickDuration * 100 );

				if ( m_LoadPercent < 85 )
				{
					if ( Utils::GetDuration( m_LastLogLoad, m_TickEnd ) > m_LogLoadPeriod )
					{
						m_LastLogLoad = m_TickEnd;
						LOG_SUCC( "System <{}> thread load {}%", m_Name, m_LoadPercent );
					}
					std::this_thread::sleep_until( m_Components->Past.Time.GetTargetTickEnd() );
				}
			}
		}
	}
}

void System::Kill()
{
	LOG_DEBUG( "Killing <{}> system", m_Name );
	m_Enabled = false;
}