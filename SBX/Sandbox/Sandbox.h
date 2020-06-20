#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "System/SystemVector.h"

class Sandbox
{
public:
	Sandbox()
	{
		LOG_STARTEND( "Initializing sandbox", "Sandbox initialized" );
		Components = std::make_shared<ComponentVectors>();
		Systems = std::make_shared<SystemVector>( Components );
	}

	~Sandbox()
	{
		LOG_INFO( "Sandbox destructed" );
	}

	void Run()
	{
		LOG_STARTEND( "Running sandbox", "Sandbox ran" );
		Systems->Run();
	}

	void Stop()
	{
		LOG_STARTEND( "Stopping sandbox", "Sandbox stopped" );
		Systems->Stop();
	}

	void StartTime()
	{
		TimeRate = 1;
		LOG_INFO( "Time started" );
	}

	void StopTime()
	{
		TimeRate = 0;
		LOG_INFO( "Time stopped" );
	}

	void SetTimeRate( double timeRate )
	{
		TimeRate = timeRate;
	}

private:
	double Time;
	double TimeRate;
	double Dt;

	std::shared_ptr<ComponentVectors> Components;
	std::shared_ptr<SystemVector> Systems;
};