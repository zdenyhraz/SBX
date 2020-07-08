#pragma once
#include "Stdafx.h"
#include "SubSystem.h"
#include "Component/ComponentVectors.h"
#include "Manager/ManagerVector.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, const std::string &name, bool async = false );

	void Run();

	void Kill();

	virtual void Tick() = 0;

protected:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
	std::vector<std::shared_ptr<SubSystem>> m_SubSystems;
	std::string m_Name;
	bool m_Enabled;
	bool m_Async;

private:
	long long m_LogLoadPeriod;
	long long m_TickDuration;
	int m_LoadPercent;
	std::chrono::time_point<std::chrono::steady_clock> m_TickStart;
	std::chrono::time_point<std::chrono::steady_clock> m_TickEnd;
	std::chrono::time_point<std::chrono::steady_clock> m_LastLogLoad;
	std::chrono::time_point<std::chrono::steady_clock> m_LastTargetTickEnd;
};