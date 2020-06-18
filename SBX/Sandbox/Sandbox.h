#pragma once
#include "Stdafx.h"
#include "Component/ComponentVector/ComponentVectors.h"

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