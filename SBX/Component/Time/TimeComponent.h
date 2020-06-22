#pragma once
#include "Stdafx.h"
#include "Component.h"

class TimeComponent : public Component
{
public:
	static constexpr double RefreshRate = 100;

	TimeComponent();

	double GetTime() const;

	double GetDelta() const;

	double GetTimeRate() const;

	bool GetRunning() const;

	void Advance();

	void SetTimeRate( double timerate );

	void SetRunning( bool running );

	void StartTime();

	void StopTime();

private:
	double Time;
	double Delta;
	double TimeRate;
	bool Running;
	std::mutex Mutex;

	void ResetDelta();

};