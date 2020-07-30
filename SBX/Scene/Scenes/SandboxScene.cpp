#include "SandboxScene.h"

SandboxScene::SandboxScene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems ):
	Scene( components, managers, systems ),
	m_ClearColor( 0.f, 69.f / 255, 204.f / 255, 1.f )
{

}

void SandboxScene::OnStart()
{
	int initEntityCnt = 0;

	if ( initEntityCnt > 0 )
		LOG_DEBUG( "Initializing {} entities", initEntityCnt );

	for ( int i = 0; i < initEntityCnt; i++ )
	{
		m_Managers->m_EntityManager->CreateEntity( EntityInfoComponent::EntityType::Entity );
	}

	for ( auto &mod : m_Components->Models.GetContainer() )
	{
		mod.second.Color = cv::Scalar( Utils::Rand01(), Utils::Rand01(), Utils::Rand01() );
		mod.second.Size = Utils::Clamp( Utils::Rand01() * 2, 0.3f, 2.f );
	}

	for ( auto &pos : m_Components->Positions.GetContainer() )
	{
		const float spread = 1.0;
		pos.second.Position.x = Utils::Rand11() * spread;
		pos.second.Position.y = Utils::Rand11() * spread;
		pos.second.Position.z = Utils::Rand11() * spread;
	}

	for ( auto &vel : m_Components->Velocities.GetContainer() )
	{
		const float spread = 1.0;
		vel.second.Velocity.x = Utils::Rand11() * spread;
		vel.second.Velocity.y = Utils::Rand11() * spread;
		vel.second.Velocity.z = Utils::Rand11() * spread;
	}

	for ( auto &ag : m_Components->Agents.GetContainer() )
	{
		ag.second.MovementBehaviour = AgentComponent::Swarming;
	}

	if ( initEntityCnt >= 2 )
	{
		m_Components->EntityInfos.Find( 0 ).Name = "Sasko";
		m_Components->Models.Find( 0 ).Size = 3;
		m_Components->Models.Find( 0 ).Color = cv::Scalar( 0.7, 0.41, 1 );

		m_Components->EntityInfos.Find( 1 ).Name = "Zdeny";
		m_Components->Models.Find( 1 ).Size = 3;
		m_Components->Models.Find( 1 ).Color = cv::Scalar( 0.2, 0.8, 0.2 );
	}

	m_Shader = std::make_shared<Shader>( "Resources/Shaders/Vertex.shader", "Resources/Shaders/Fragment.shader" );
	m_Shader->Bind();
	m_Shader->SetUniform1i( "u_Texture", 0 );

	Renderer::m_RendererStorage->AddTexture( "entity", "Resources/Textures/sasa.png" );
	Renderer::m_RendererStorage->AddTexture( "ground", "Resources/Textures/ground.jpg" );
	Renderer::m_RendererStorage->AddTexture( "box", "Resources/Textures/box.jpg" );
	Renderer::m_RendererStorage->AddTexture( "fence", "Resources/Textures/fence.png" );
}

void SandboxScene::OnStop()
{
	for ( auto &ent : m_Components->EntityInfos.GetContainer() )
	{
		m_Managers->m_EntityManager->DeleteEntity( ent.first );
	}
}

void SandboxScene::OnUpdate()
{
	float dt = m_Components->Time.Delta;

	m_Systems->Attractor->Tick( dt );
	m_Systems->Avoidance->Tick( dt );
	m_Systems->Event->Tick( dt );
	m_Systems->Health->Tick( dt );
	m_Systems->Logic->Tick( dt );
	m_Systems->Seeking->Tick( dt );
	m_Systems->Swarm->Tick( dt );
	m_Systems->Movement->Tick( dt );
	m_Systems->Time->Tick( dt );

	m_Shader->UpdateMvp();
}

void SandboxScene::OnRender()
{
	glClearColor( m_ClearColor.x, m_ClearColor.y, m_ClearColor.z, m_ClearColor.w );

	//floor
	const float floorLength = 2.0f;
	const float floorSize = 0.2f;
	const float floorCnt = ( int )( floorLength / floorSize );
	for ( int x = 0; x < floorCnt; x++ )
		for ( int y = 0; y < floorCnt; y++ )
			Renderer::DrawQuad( glm::vec3( ( 0.5f + x - floorCnt / 2 ) * floorSize, ( 0.5f + y - floorCnt / 2 ) * floorSize, 0 ), glm::vec3( 0, 0, 0 ), glm::vec2( floorSize, floorSize ), m_Shader.get(), "ground" );

	//cubes
	const glm::vec3 cubeSize( 0.02f, 0.02f, 0.02f );
	Renderer::DrawCube( glm::vec3( 0, 0, 0 ), glm::vec3( 0, 0, 0 ), cubeSize, m_Shader.get(), "box" );
	Renderer::DrawCube( glm::vec3( 0, 0.05, 0 ), glm::vec3( 0, glm::radians( +45.0f ), 0 ), cubeSize, m_Shader.get(), "box" );
	Renderer::DrawCube( glm::vec3( -0.01, 0, 0.02 ), glm::vec3( 0, glm::radians( -45.0f ), 0 ), cubeSize, m_Shader.get(), "box" );
	Renderer::DrawCube( glm::vec3( -0.02, 0, 0.04 ), glm::vec3( 0, glm::radians( +0.0f ), 0 ), cubeSize, m_Shader.get(), "box" );

	//fence
	const float fenceLength = 2.0f;
	const float fenceSize = 0.02f;
	const int fenceCnt = ( int )( fenceLength / fenceSize );
	for ( int i = 0; i < fenceCnt; i++ )
	{
		Renderer::DrawQuad( glm::vec3( -1, ( 0.5f + i - fenceCnt / 2 ) * fenceSize, fenceSize / 2 ), glm::vec3( glm::radians( 90.0f ), 0, glm::radians( 90.0f ) ), glm::vec2( fenceSize, fenceSize ), m_Shader.get(), "fence" );
		Renderer::DrawQuad( glm::vec3( +1, ( 0.5f + i - fenceCnt / 2 ) * fenceSize, fenceSize / 2 ), glm::vec3( glm::radians( 90.0f ), 0, glm::radians( 90.0f ) ), glm::vec2( fenceSize, fenceSize ), m_Shader.get(), "fence" );
		Renderer::DrawQuad( glm::vec3( ( 0.5f + i - fenceCnt / 2 ) * fenceSize, +1, fenceSize / 2 ), glm::vec3( glm::radians( 90.0f ), 0, 0 ), glm::vec2( fenceSize, fenceSize ), m_Shader.get(), "fence" );
		Renderer::DrawQuad( glm::vec3( ( 0.5f + i - fenceCnt / 2 ) * fenceSize, -1, fenceSize / 2 ), glm::vec3( glm::radians( 90.0f ), 0, 0 ), glm::vec2( fenceSize, fenceSize ), m_Shader.get(), "fence" );
	}
}

void SandboxScene::OnImGuiRender()
{
	ImGui::Begin( "Stuffs" );
	ImGui::SetWindowFontScale( 1.5 );
	ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate );
	ImGui::NewLine();
	ImGui::ColorEdit4( "Clear color", &m_ClearColor.x );
	ImGui::SliderFloat3( "Camera position", &Renderer::m_Camera->m_ViewPos.x, -5, 5 );
	ImGui::SliderFloat3( "Camera direction", &Renderer::m_Camera->m_ViewDir.x, -5, 5 );
	ImGui::SliderFloat( "Camera Fov", &Renderer::m_Camera->m_CameraFov, 5.0f, 180.f );
	ImGui::SliderFloat( "Camera pitch", &Renderer::m_Camera->m_Pitch, 1.f, 179.f );
	ImGui::SliderFloat( "Camera yaw", &Renderer::m_Camera->m_Yaw, -180, 180 );
	ImGui::End();
}


