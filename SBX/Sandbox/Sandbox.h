#pragma once
#include "Stdafx.h"
#include "Entity/Entity.h"
#include "Component/Component.h"
#include "System/System.h"

class Sandbox
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

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
};