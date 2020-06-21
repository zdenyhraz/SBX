#pragma once
#include "Stdafx.h"
#include "Component.h"

class TimeComponent : public Component
{
public:
	double m_Time = 0;
	double m_TimeRate = 1;
	double m_Delta = 1. / 60.;

private:
};