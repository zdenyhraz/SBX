#include "NomNomAgentSystem.h"

NomNomAgentSystem::NomNomAgentSystem( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	AgentSubSystem( components, managers ),
	m_VelAngleThreshold( Utils::ToRadians( 50 ) ),
	m_RangeAgentSizeScale( 2e-3 ),
	m_GrowthRatio( 0.3 )
{

}

void NomNomAgentSystem::Tick()
{
	for ( auto &agent : m_Components->Past->Agents.GetContainer() )
	{
		int agentId = agent.first;
		auto &agentPos = m_Components->Past->Positions.Find( agentId ).Position;
		auto &agentVel = m_Components->Past->Velocities.Find( agentId ).Velocity;
		auto &agentSiz = m_Components->Past->Models.Find( agentId ).Size;

		for ( auto &otherAgent : m_Components->Past->Agents.GetContainer() )
		{
			int otherAgentId = otherAgent.first;

			if ( otherAgentId == agentId )
			{
				continue;
			}

			auto &otherAgentPos = m_Components->Past->Positions.Find( otherAgentId ).Position;
			auto &otherAgentVel = m_Components->Past->Velocities.Find( otherAgentId ).Velocity;
			auto &otherAgentSiz = m_Components->Past->Models.Find( otherAgentId ).Size;

			auto direction = otherAgentPos - agentPos;
			double distance = cv::norm( direction );

			if ( distance < ( m_RangeAgentSizeScale * ( agentSiz + otherAgentSiz ) ) )
			{
				double velAngle = Utils::GetAngle( agentVel, otherAgentVel );
				if ( abs( velAngle ) < m_VelAngleThreshold )
				{
					double velDirAngle = Utils::GetAngle( agentVel, direction );
					if ( abs( velDirAngle ) < Utils::Pi )
					{
						NomNom( agentId, otherAgentId );
					}
					else
					{
						NomNom( otherAgentId, agentId );
					}
				}
			}
		}
	}
}

void NomNomAgentSystem::NomNom( int predatorId, int victimId )
{
	if ( 1 )
	{
		std::string predatorName = m_Components->Past->EntityInfos.Find( predatorId ).Name == "" ? std::to_string( predatorId ) : m_Components->Past->EntityInfos.Find( predatorId ).Name;
		std::string victimName = m_Components->Past->EntityInfos.Find( victimId ).Name == "" ? std::to_string( victimId ) : m_Components->Past->EntityInfos.Find( victimId ).Name;

		auto &agentPos = m_Components->Past->Positions.Find( predatorId ).Position;
		auto &agentVel = m_Components->Past->Velocities.Find( predatorId ).Velocity;

		auto &otherAgentPos = m_Components->Past->Positions.Find( victimId ).Position;
		auto &otherAgentVel = m_Components->Past->Velocities.Find( victimId ).Velocity;

		auto direction = otherAgentPos - agentPos;
		int velAngle = ( int )Utils::ToDegrees( Utils::GetAngle( agentVel, otherAgentVel ) );
		int velDirAngle = ( int )Utils::ToDegrees( Utils::GetAngle( agentVel, direction ) );

		LOG_DEBUG( "Agent {} eats agent {}! (velAngle={}, velDirAngle={})", predatorName, victimName, velAngle, velDirAngle );
	}

	m_Components->Past->Models.Find( predatorId ).Size += ( int )( m_GrowthRatio * m_Components->Past->Models.Find( victimId ).Size );
	m_Managers->m_EntityManager->DeleteEntity( victimId );
}
