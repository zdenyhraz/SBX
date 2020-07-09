#pragma once
#include "Manager/Manager.h"

class TimeManager : public Manager
{
public:
	TimeManager( std::shared_ptr<ComponentVectors> components );

	void Advance();

	double GetTime() const;

	double GetDelta() const;

	double GetTimeRate() const;

	bool GetRunning() const;

	long long GetTickId() const;

	std::chrono::time_point<std::chrono::steady_clock> GetTargetTickEnd() const;

	void SetTargetTickEnd( const std::chrono::time_point<std::chrono::steady_clock> &time );

	void SetTimeRate( double timerate );

	void StartTime();

	void StopTime();

private:
	void ResetDelta();

	void SetRunning( bool running );
};