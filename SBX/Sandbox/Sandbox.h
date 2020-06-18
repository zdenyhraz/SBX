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

private:
	double Time;
	double TimeRate;
	double Dt;
};