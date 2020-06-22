#include "Sandbox.h"

Sandbox::Sandbox()
{
	LOG_STARTEND( "Creating sandbox", "Sandbox created" );
	m_Components = std::make_shared<ComponentVectors>();
	m_EntityManager = std::make_shared<EntityManager>( m_Components );

	m_Systems = std::make_shared<SystemVector>( m_Components );
	m_SystemManager = std::make_shared<SystemManager>( m_Systems );

	Init();
	RunSystems();
}

Sandbox::~Sandbox()
{
	EndSystems();
	LOG_INFO( "Sandbox destructed" );
}

void Sandbox::Init()
{
	LOG_STARTEND( "Initializing sandbox world", "Sandbox world initialized" );
	InitTest();
}

void Sandbox::InitTest()
{

	int initEntityCnt = 100;
	LOG_DEBUG( "Initializing {} entities", initEntityCnt );

	for ( int i = 0; i < initEntityCnt; i++ )
	{
		m_EntityManager->CreateEntity( EntityInfoComponent::EntityType::Entity );
	}

	m_Components->EntityInfos.Find( 0 ).Name = "Saska";

	for ( auto &mod : m_Components->Models.Data )
	{
		mod.second.Color = cv::Scalar( Utils::Rand01(), Utils::Rand01(), Utils::Rand01() );
		mod.second.Size = ( int )( Utils::Rand01() * 30 );
	}

	for ( auto &pos : m_Components->Positions.Data )
	{
		const double spread = 0.8;
		pos.second.Position.x = Utils::Rand11() * spread;
		pos.second.Position.y = Utils::Rand11() * spread;
	}

	for ( auto &vel : m_Components->Velocities.Data )
	{
		vel.second.Velocity.x = Utils::Rand11() * 0.5;
		vel.second.Velocity.y = Utils::Rand11() * 0.5;
	}
}

void Sandbox::RunSystems()
{
	LOG_STARTEND( "Running systems", "Systems ran" );
	m_Systems->Run();
}

void Sandbox::EndSystems()
{
	LOG_STARTEND( "Ending systems", "Systems stopped" );
	m_Systems->End();
}