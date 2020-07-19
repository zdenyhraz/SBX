#include "Sandbox.h"
#include "Utils/MathUtils.h"
#include "Utils/ThreadUtils.h"
#include "Scene/Scenes/TestScene.h"

Sandbox::Sandbox()
{
	LOG_STARTEND( "Creating sandbox", "Sandbox created" );

	// 1) construct components
	m_Components = std::make_shared<ComponentVectors>();

	// 2) construct managers acting on components
	m_Managers = std::make_shared<ManagerVector>( m_Components );

	// 3) construct systems acting on components directly or via managers
	m_Systems = std::make_shared<SystemVector>( m_Components, m_Managers );

	// 4) construct a scene that ticks the relevant systems
	m_Scene = std::make_unique<TestScene>( m_Components, m_Managers, m_Systems );

	// 5) initialize the sandbox world
	Init();
}

Sandbox::~Sandbox()
{
	LOG_INFO( "Sandbox destroyed" );
}

void Sandbox::Run()
{
	LOG_DEBUG( "Running sandbox from thread {}", Utils::ThisThreadId() );
	m_Scene->Run();
}

void Sandbox::Init()
{
	LOG_STARTEND( "Initializing sandbox world", "Sandbox world initialized" );
	//m_Managers->m_TimeManager->StopTime();
	InitTest();
}

void Sandbox::InitTest()
{
	int initEntityCnt = 300;
	LOG_DEBUG( "Initializing {} entities", initEntityCnt );

	for ( int i = 0; i < initEntityCnt; i++ )
	{
		m_Managers->m_EntityManager->CreateEntity( EntityInfoComponent::EntityType::Entity );
	}

	for ( auto &mod : m_Components->Models.GetContainer() )
	{
		mod.second.Color = cv::Scalar( Utils::Rand01(), Utils::Rand01(), Utils::Rand01() );
		mod.second.Size = 5;//std::max( ( int )( Utils::Rand01() * 15 ), 5 );
	}

	for ( auto &pos : m_Components->Positions.GetContainer() )
	{
		const double spread = 1.0;
		pos.second.Position.x = Utils::Rand11() * spread;
		pos.second.Position.y = Utils::Rand11() * spread;
	}

	for ( auto &vel : m_Components->Velocities.GetContainer() )
	{
		const double spread = 1.0;
		vel.second.Velocity.x = Utils::Rand11() * spread;
		vel.second.Velocity.y = Utils::Rand11() * spread;
	}

	for ( auto &ag : m_Components->Agents.GetContainer() )
	{
		ag.second.MovementBehaviour = AgentComponent::Swarming;
	}

	if ( 1 )
	{
		m_Components->EntityInfos.Find( 0 ).Name = "Sasko";
		m_Components->Models.Find( 0 ).Size = 15;
		m_Components->Models.Find( 0 ).Color = cv::Scalar( 0.7, 0.41, 1 );

		m_Components->EntityInfos.Find( 1 ).Name = "Zdeny";
		m_Components->Models.Find( 1 ).Size = 15;
		m_Components->Models.Find( 1 ).Color = cv::Scalar( 0.2, 0.8, 0.2 );
	}
}
