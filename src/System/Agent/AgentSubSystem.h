#pragma once
#include "System/System.h"

class AgentSubSystem
{
public:

	AgentSubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	virtual void Tick() = 0;

protected:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;

private:
};