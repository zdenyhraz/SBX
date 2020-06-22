#include "TimeComponent.h"

TimeComponent::TimeComponent() :
	Time( 0 ),
	TimeRate( 1 ),
	Delta( 1. / RefreshRate ),
	Running( true )
{

}

double TimeComponent::GetTime() const
{
	return Time;
}

double TimeComponent::GetDelta() const
{
	return Delta;
}

double TimeComponent::GetTimeRate() const
{
	return TimeRate;
}

bool TimeComponent::GetRunning() const
{
	return Running;
}

void TimeComponent::Advance()
{
	Time += Delta;
}

void TimeComponent::SetTimeRate( double timerate )
{
	std::lock_guard<std::mutex> lock( Mutex );

	TimeRate = timerate;
	if ( Running )
	{
		ResetDelta();
	}
	LOG_INFO( "Time rate set to {}", timerate );
}

void TimeComponent::SetRunning( bool running )
{
	std::lock_guard<std::mutex> lock( Mutex );

	//stopping
	if ( Running && !running )
	{
		Delta = 0;
	}

	//starting
	if ( !Running && running )
	{
		ResetDelta();
	}

	Running = running;
}

void TimeComponent::StartTime()
{
	SetRunning( true );
	LOG_INFO( "Time started at {}", GetTime() );
}

void TimeComponent::StopTime()
{
	SetRunning( false );
	LOG_INFO( "Time stopped at {}", GetTime() );
}

void TimeComponent::ResetDelta()
{
	Delta = 1. / RefreshRate * TimeRate;
}