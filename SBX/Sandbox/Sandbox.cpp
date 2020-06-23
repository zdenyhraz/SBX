#include "Sandbox.h"
#include "Utils/MathUtils.h"
#include "Utils/ThreadUtils.h"

Sandbox::Sandbox()
{
	LOG_STARTEND( "Creating sandbox", "Sandbox created" );

	// 1) construct components
	m_Components = std::make_shared<ComponentVectors>();

	// 2) construct managers acting on components
	m_Managers = std::make_shared<ManagerVector>( m_Components );

	// 3) construct systems that act on components directly and/or via managers
	m_Systems = std::make_shared<SystemVector>( m_Components, m_Managers );

	// 4) initialize the sandbox world
	Init();
}

Sandbox::~Sandbox()
{
	Kill();
	LOG_INFO( "Sandbox destroyed" );
}

void Sandbox::Run()
{
	LOG_DEBUG( "Running sandbox from thread {}", Utils::ThisThreadId() );
	m_Systems->Run();
}

void Sandbox::Kill()
{
	LOG_DEBUG( "Killing sandbox from thread {}", Utils::ThisThreadId() );
	m_Systems->Kill();
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
		m_Managers->m_EntityManager->CreateEntity( EntityInfoComponent::EntityType::Entity );
	}

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

	m_Components->EntityInfos.Find( 0 ).Name = "Saska";
	m_Components->Models.Find( 0 ).Size = 50;
	m_Components->Models.Find( 0 ).Color = cv::Scalar( 0.7, 0.41, 1 );
}
