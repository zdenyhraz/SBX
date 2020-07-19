#pragma once
#include "Manager/Manager.h"

class TimeManager : public Manager
{
public:
	TimeManager( std::shared_ptr<ComponentVectors> components );

	void Advance( float dt );

	float GetTime() const;

	float GetDelta() const;

	float GetTimeRate() const;

	bool GetRunning() const;

	long long GetTickId() const;

	void SetTimeRate( float timerate );

	void StartTime();

	void StopTime();

private:
	void ResetDelta();

	void SetRunning( bool running );
};