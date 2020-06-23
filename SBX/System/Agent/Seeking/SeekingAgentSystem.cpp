#include "SeekingAgentSystem.h"

SeekingAgentSystem::SeekingAgentSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	m_Components( components ),
	m_Managers( managers ),
	m_SeekSpeed( 0.2 )
{

}

void SeekingAgentSystem::Tick()
{
	for ( auto &agent : m_Components->SeekingAgents.Data )
	{
		int agentId = agent.first;
		int targetId = agent.second.TargetId;
		auto &agentPos = m_Components->Positions.Find( agentId );
		auto &targetPos = m_Components->Positions.Find( targetId );
		auto direction = targetPos.Position - agentPos.Position;
		m_Components->Velocities.Find( agentId ).Velocity = direction / cv::norm( direction ) * m_SeekSpeed;
	}
}
