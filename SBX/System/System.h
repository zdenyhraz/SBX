#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "Manager/ManagerVector.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::string &&name, double refreshRate = TimeComponent::RefreshRate, bool logLoad = true );

	void Run();

	void Kill();

	virtual void Tick() = 0;

protected:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
	std::string m_Name;
	bool m_Enabled;
	double m_RefreshRate;

private:
	bool m_LogLoad;
	long long m_LogLoadPeriod;
	long long m_TargetTickDuration;
	long long m_TickDuration;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickStart;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_TickEnd;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_LastLogLoad;
	int m_LoadPercent;
};