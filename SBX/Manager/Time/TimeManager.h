#pragma once
#include "Manager/Manager.h"

class TimeManager: public Manager
{
public:
	TimeManager( std::shared_ptr<ComponentVectors> components );

	double GetTime() const;

	double GetDelta() const;

	double GetTimeRate() const;

	bool GetRunning() const;

	void SetTimeRate( double timerate );

	void SetRunning( bool running );

	void StartTime();

	void StopTime();

private:
	void ResetDelta();
};

