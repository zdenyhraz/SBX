#include "NomNomAgentSystem.h"

NomNomAgentSystem::NomNomAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	m_Components( components ),
	m_Managers( managers )
{

}

void NomNomAgentSystem::Tick()
{
	for ( auto &agent : m_Components->NomNomAgents.Data )
	{
		int agentId = agent.first;
		auto &agentPos = m_Components->Positions.Data.find( agentId )->second.Position;
		auto &agentVel = m_Components->Velocities.Data.find( agentId )->second.Velocity;
		auto &agentSiz = m_Components->Models.Data.find( agentId )->second.Size;

		for ( auto &otherAgent : m_Components->NomNomAgents.Data )
		{
			int otherAgentId = otherAgent.first;

			if ( otherAgentId == agentId )
			{
				continue;
			}

			auto &otherAgentPos = m_Components->Positions.Data.find( otherAgentId )->second.Position;
			auto &otherAgentVel = m_Components->Velocities.Data.find( otherAgentId )->second.Velocity;

			double distance = cv::norm( agentPos - otherAgentPos );

			if ( distance < agentSiz )
			{

				//nomnom
			}

		}

	}
}
