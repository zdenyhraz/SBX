#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components, std::string &&name, double refreshRate = TimeComponent::RefreshRate );

	void Run();

	void Kill();

	virtual void Tick() = 0;

protected:
	std::shared_ptr<ComponentVectors> m_Components;
	std::string m_Name;
	bool m_Enabled;
	double m_RefreshRate;
	long long m_TargetTickDuration;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickStart;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickEnd;

};