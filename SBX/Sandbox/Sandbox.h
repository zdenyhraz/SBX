#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors/ComponentVectors.h"
#include "System/VelocitySystem.h"

class Sandbox
{
public:
	Sandbox()
	{
		LOG_INFO( "Sandbox initialized" );
	}

	~Sandbox()
	{
		LOG_INFO( "Sandbox destructed" );
	}

	void Start()
	{
		TimeRate = 1;
		VelocitySystem System( Components );//test!!!!!!!!!!!!!!!!!!!!

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

	ComponentVectors Components;
};