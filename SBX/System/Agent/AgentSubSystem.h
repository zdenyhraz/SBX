#pragma once
#include "System/System.h"

class AgentSubSystem
{
public:

	AgentSubSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	virtual void Tick() = 0;

protected:
	std::shared_ptr<PastFutureComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;

private:
};