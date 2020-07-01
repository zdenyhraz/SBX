#include "System/System.h"
#include "Utils/ThreadUtils.h"
#include "Utils/TimeUtils.h"
#include "Utils/MathUtils.h"

System::System( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, const std::string &name, bool async ) :
	m_Components( components ),
	m_Managers( managers ),
	m_Name( name ),
	m_Enabled( true ),
	m_LogLoadPeriod( 15 * 1000 ),
	m_Async( async ),
	m_TickId( 0 )
{
	m_LastLogLoad = Utils::GetTimeNow();
}

void System::Run()
{
	LOG_DEBUG( "Running <{}> system on thread {}", m_Name, Utils::ThisThreadId() );
	m_Enabled = true;

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
			if ( m_TickId && m_TickId >= m_Components->Time.GetTickId() )
			{
				continue;
			}

			m_TickStart = Utils::GetTimeNow();
			Tick();
			m_TickEnd = Utils::GetTimeNow();

			m_TickId++;
			m_TickDuration = Utils::GetDuration( m_TickStart, m_TickEnd );
			m_LoadPercent = ( int )( ( double )m_TickDuration / TimeComponent::TargetTickDuration * 100 );

			if ( m_LoadPercent >= 100 )
			{
				continue;
			}
			else
			{
				if ( Utils::GetDuration( m_LastLogLoad, m_TickEnd ) > m_LogLoadPeriod )
				{
					m_LastLogLoad = m_TickEnd;
					LOG_SUCC( "System <{}> thread load {}%", m_Name, m_LoadPercent );
				}
			}

			std::this_thread::sleep_until( m_Components->Time.GetTargetTickEnd() );
		}
	}
}

void System::Kill()
{
	LOG_DEBUG( "Killing <{}> system", m_Name );
	m_Enabled = false;
}