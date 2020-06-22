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

	void Advance()
	{
		Time += Delta;
	}

	void SetTimeRate( double timerate )
	{
		TimeRate = timerate;
		ResetDelta();
		Delta *= timerate;
		LOG_INFO( "Time rate set to {}", timerate );
	}

	void SetRunning( bool running )
	{
		Running = running;
		if ( !Running )
		{
			Delta = 0;
		}
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
	double TimeRate;
	double Delta;
	bool Running;

	void ResetDelta()
	{
		Delta = 1. / RefreshRate;
	}

};