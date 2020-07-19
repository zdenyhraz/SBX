#include "TimeManager.h"

TimeManager::TimeManager( std::shared_ptr<ComponentVectors> components ) :
	Manager( components )
{

}

void TimeManager::Advance( float dt )
{
	m_Components->Time.Time += dt;
	m_Components->Time.TickId++;
}

float TimeManager::GetTime() const
{
	return m_Components->Time.Time;
}

float TimeManager::GetDelta() const
{
	return m_Components->Time.Delta;
}

float TimeManager::GetTimeRate() const
{
	return m_Components->Time.TimeRate;
}

bool TimeManager::GetRunning() const
{
	return m_Components->Time.Running;
}

long long TimeManager::GetTickId() const
{
	return m_Components->Time.TickId;
}

void TimeManager::SetTimeRate( float timerate )
{
	std::lock_guard<std::mutex> lock( m_mutex );

	m_Components->Time.TimeRate = timerate;
	if ( m_Components->Time.Running )
	{
		ResetDelta();
	}
	LOG_INFO( "Time rate set to {}", timerate );
}

void TimeManager::StartTime()
{
	SetRunning( true );
	LOG_INFO( "Time started at {}", GetTime() );
}

void TimeManager::StopTime()
{
	SetRunning( false );
	LOG_INFO( "Time stopped at {}", GetTime() );
}

void TimeManager::ResetDelta()
{
	m_Components->Time.Delta = 1.0f / TimeComponent::RefreshRate * m_Components->Time.TimeRate;
}

void TimeManager::SetRunning( bool running )
{
	std::lock_guard<std::mutex> lock( m_mutex );

	//stopping
	if ( m_Components->Time.Running && !running )
	{
		m_Components->Time.Delta = 0;
	}

	//starting
	if ( !m_Components->Time.Running && running )
	{
		ResetDelta();
	}

	m_Components->Time.Running = running;
}