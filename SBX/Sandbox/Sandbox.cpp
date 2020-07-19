#include "Sandbox.h"
#include "Utils/MathUtils.h"
#include "Utils/ThreadUtils.h"
#include "Scene/Scenes/SandboxScene.h"

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
	m_Scene = std::make_unique<SandboxScene>( m_Components, m_Managers, m_Systems );
}

Sandbox::~Sandbox()
{
	LOG_INFO( "Sandbox destroyed" );
}

void Sandbox::Run()
{
	LOG_DEBUG( "Running sandbox from thread {}", Utils::ThisThreadId() );
	std::thread thread( &Scene::Run, m_Scene.get() );
	thread.detach();
}

