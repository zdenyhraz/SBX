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
		Delta( 1. / RefreshRate )
	{

	}

	double GetTime() const
	{
		return Time;
	}

	void Advance()
	{
		Time += Delta;
	}

	double GetDelta() const
	{
		return Delta;
	}

	double GetTimeRate() const
	{
		return TimeRate;
	}

	void SetTimeRate( double timerate )
	{
		TimeRate = timerate;
		ResetDelta();
		Delta *= timerate;
	}

private:
	double Time;
	double TimeRate;
	double Delta;

	void ResetDelta()
	{
		Delta = 1. / RefreshRate;
	}

};