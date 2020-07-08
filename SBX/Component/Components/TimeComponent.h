#pragma once
#include "Component/Component.h"

struct TimeComponent : Component
{
	static constexpr int RefreshRate = 75;
	static constexpr long long TargetTickDuration = ( long long )( 1. / RefreshRate * 1000 );

	TimeComponent() :
		Time( 0 ),
		TimeRate( 1 ),
		Delta( 1. / RefreshRate ),
		Running( true ),
		TickId( 0 )
	{
		TargetTickEnd = Utils::GetTimeNow();
	}

	void Advance()
	{
		Time += Delta;
		TargetTickEnd += std::chrono::milliseconds( TimeComponent::TargetTickDuration );
		TickId++;
	}

	double GetTime() const
	{
		return Time;
	}

	double GetDelta() const
	{
		return Delta;
	}

	double GetTimeRate() const
	{
		return TimeRate;
	}

	bool GetRunning() const
	{
		return Running;
	}

	long long GetTickId() const
	{
		return TickId;
	}

	std::chrono::time_point<std::chrono::steady_clock> GetTargetTickEnd() const
	{
		return TargetTickEnd;
	}

	void SetTargetTickEnd( const std::chrono::time_point<std::chrono::steady_clock> &time )
	{
		TargetTickEnd = time;
	}

	void SetTimeRate( double timerate )
	{
		std::lock_guard<std::mutex> lock( m_mutex );

		TimeRate = timerate;
		if ( Running )
		{
			ResetDelta();
		}
		LOG_INFO( "Time rate set to {}", timerate );
	}

	void StartTime()
	{
		SetRunning( true );
		LOG_INFO( "Time started at {}", GetTime() );
	}

	void StopTime()
	{
		SetRunning( false );
		LOG_INFO( "Time stopped at {}", GetTime() );
	}

private:
	double Time;
	double Delta;
	double TimeRate;
	bool Running;
	long long TickId;
	std::mutex m_mutex;
	std::chrono::time_point<std::chrono::steady_clock> TargetTickEnd;

	void ResetDelta()
	{
		Delta = 1. / TimeComponent::RefreshRate * TimeRate;
	}

	void SetRunning( bool running )
	{
		std::lock_guard<std::mutex> lock( m_mutex );

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
};