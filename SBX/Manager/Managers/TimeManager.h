#pragma once
#include "Manager/Manager.h"

class TimeManager : public Manager
{
public:
	TimeManager( std::shared_ptr<ComponentVectors> components );

	void Advance();

	float GetTime() const;

	float GetDelta() const;

	float GetTimeRate() const;

	bool GetRunning() const;

	long long GetTickId() const;

	std::chrono::time_point<std::chrono::steady_clock> GetTargetTickEnd() const;

	void SetTargetTickEnd( const std::chrono::time_point<std::chrono::steady_clock> &time );

	void SetTimeRate( float timerate );

	void StartTime();

	void StopTime();

private:
	void ResetDelta();

	void SetRunning( bool running );
};