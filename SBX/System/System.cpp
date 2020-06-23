#include "System/System.h"
#include "Utils/ThreadUtils.h"
#include "Utils/TimeUtils.h"
#include "Utils/MathUtils.h"

System::System( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::string &&name, double refreshRate ) :
	m_Components( components ),
	m_Managers( managers ),
	m_Name( std::move( name ) ),
	m_Enabled( true ),
	m_RefreshRate( refreshRate )
{
	m_TargetTickDuration = ( long long )( 1. / m_RefreshRate * 1e6 );
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

		std::this_thread::sleep_for( std::chrono::microseconds( std::max( m_TargetTickDuration - Utils::GetDuration( m_TickStart, m_TickEnd ), 0ll ) ) );
	}
}

void System::Kill()
{
	LOG_DEBUG( "Killing <{}> system", m_Name );
	m_Enabled = false;
}