#pragma once
#include "Stdafx.h"
#include "Component/Component.h"

class TimeComponent : public Component
{
public:
	static constexpr double RefreshRate = 100;

	TimeComponent() :
		Time( 0 ),
		TimeRate( 1 ),
		Delta( 1. / RefreshRate ),
		Running( true )
	{

	}

	void Advance()
	{
		Time += Delta;
	}

	double Time;
	double Delta;
	double TimeRate;
	bool Running;
};