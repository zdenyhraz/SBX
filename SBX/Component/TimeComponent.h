#pragma once
#include "Stdafx.h"
#include "Component.h"

class TimeComponent : public Component
{
public:
	static constexpr double RefreshRate = 100;

	TimeComponent():
		m_Time( 0 ),
		m_TimeRate( 1 ),
		m_Delta( 1. / RefreshRate )
	{

	}

	double GetTime() const
	{
		return m_Time;
	}

	void Advance()
	{
		m_Time += m_Delta;
	}

	double GetDelta() const
	{
		return m_Delta;
	}

	double GetTimeRate() const
	{
		return m_TimeRate;
	}

	void SetTimeRate( double timerate )
	{
		m_TimeRate = timerate;
		ResetDelta();
		m_Delta *= timerate;
	}

private:
	double m_Time;
	double m_TimeRate;
	double m_Delta;

	void ResetDelta()
	{
		m_Delta = 1. / RefreshRate;
	}

};