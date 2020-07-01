#pragma once
#include "System/Agent/AgentSubSystem.h"

class NomNomAgentSystem : public AgentSubSystem
{
public:

	NomNomAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
	double m_NomAngleThreshold;
};
