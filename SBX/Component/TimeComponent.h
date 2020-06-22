#pragma once
#include "Stdafx.h"
#include "Component.h"

class TimeComponent : public Component
{
public:
	static constexpr double RefreshRate = 100;

	TimeComponent():
		Time( 0 ),
		TimeRate( 1 ),
		Delta( 1. / RefreshRate ),
		Running( true )
	{

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

	void Advance()
	{
		Time += Delta;
	}

	void SetTimeRate( double timerate )
	{
		std::lock_guard<std::mutex> lock( Mutex );

		TimeRate = timerate;
		if ( Running )
		{
			ResetDelta();
		}
		LOG_INFO( "Time rate set to {}", timerate );
	}

	void SetRunning( bool running )
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
	std::mutex Mutex;

	void ResetDelta()
	{
		Delta = 1. / RefreshRate * TimeRate;
	}

};