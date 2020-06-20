#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors/ComponentVectors.h"
#include "System/SystemVector.h"

class Sandbox
{
public:
	Sandbox()
	{
		Components = std::make_shared<ComponentVectors>();
		Systems = std::make_shared<SystemVector>( Components );
		LOG_INFO( "Sandbox initialized" );
	}

	~Sandbox()
	{
		LOG_INFO( "Sandbox destructed" );
	}

	void Start()
	{
		TimeRate = 1;
	}

	void Stop()
	{
		TimeRate = 0;
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