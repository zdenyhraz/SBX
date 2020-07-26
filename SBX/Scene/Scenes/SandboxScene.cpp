#include "SandboxScene.h"

SandboxScene::SandboxScene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems ):
	Scene( components, managers, systems ),
	m_ClearColor( 0.f, 69.f / 255, 204.f / 255, 1.f )
{

}

void SandboxScene::OnStart()
{
	int initEntityCnt = 0;
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

	float sizeEntity = 0.05f;
	float sizeGround = 1.0f;
	float sizeBox = 0.1f;

	float positionsEntity[] =
	{
		-sizeEntity, -sizeEntity, 0.0f, 0.0f, 0.0f,
		+sizeEntity, -sizeEntity, 0.0f, 1.0f, 0.0f,
		+sizeEntity, +sizeEntity, 0.0f, 1.0f, 1.0f,
		-sizeEntity, +sizeEntity, 0.0f, 0.0f, 1.0f
	};

	float positionsGround[] =
	{
		-sizeGround, -sizeGround, 0.0f, 0.0f, 0.0f,
		+sizeGround, -sizeGround, 0.0f, 1.0f, 0.0f,
		+sizeGround, +sizeGround, 0.0f, 1.0f, 1.0f,
		-sizeGround, +sizeGround, 0.0f, 0.0f, 1.0f
	};

	float positionsBox[] =
	{
		-sizeBox, -sizeBox, 0.0f, 0.0f, 0.0f,
		sizeBox, -sizeBox, 0.0f, 1.0f, 0.0f,
		sizeBox, sizeBox, 0.0f, 1.0f, 1.0f,
		-sizeBox, sizeBox, 0.0f, 0.0f, 1.0f,
		-sizeBox, -sizeBox, 2.0f * sizeBox, 0.0f, 0.0f,
		sizeBox, -sizeBox, 2.0f * sizeBox, 1.0f, 0.0f,
		sizeBox, sizeBox, 2.0f * sizeBox, 1.0f, 1.0f,
		-sizeBox, sizeBox, 2.0f * sizeBox, 0.0f, 1.0f,
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	unsigned int indicesBox[] =
	{
		0, 1, 2,
		2, 3, 0,
		4, 5, 6,
		6, 7, 4,
		0, 1, 5,
		5, 4, 0,
		1, 2, 6,
		6, 5, 1,
		2, 3, 7,
		7, 6, 2,
		3, 0, 4,
		4, 7, 3
	};

	m_Ib = std::make_shared<IndexBuffer>( indices, 6 );
	m_IbBox = std::make_shared<IndexBuffer>( indicesBox, 36 );

	m_VaEntity = std::make_shared<VertexArray>();
	m_VbEntity = std::make_shared<VertexBuffer>( positionsEntity, 4 * 5 * sizeof( float ) );
	m_VblEntity = std::make_shared<VertexBufferLayout>();
	m_VblEntity->Push<float>( 3 ); //vertex position
	m_VblEntity->Push<float>( 2 ); //texture coordinate
	m_VaEntity->SetVertexBuffer( m_VbEntity, m_VblEntity );
	m_VaEntity->SetIndexBuffer( m_Ib );

	m_VaGround = std::make_shared<VertexArray>();
	m_VbGround = std::make_shared<VertexBuffer>( positionsGround, 4 * 5 * sizeof( float ) );
	m_VblGround = std::make_shared<VertexBufferLayout>();
	m_VblGround->Push<float>( 3 ); //vertex position
	m_VblGround->Push<float>( 2 ); //texture coordinate
	m_VaGround->SetVertexBuffer( m_VbGround, m_VblGround );
	m_VaGround->SetIndexBuffer( m_Ib );

	m_VaBox = std::make_shared<VertexArray>();
	m_VbBox = std::make_shared<VertexBuffer>( positionsBox, 8 * 5 * sizeof( float ) );
	m_VblBox = std::make_shared<VertexBufferLayout>();
	m_VblBox->Push<float>( 3 ); //vertex position
	m_VblBox->Push<float>( 2 ); //texture coordinate
	m_VaBox->SetVertexBuffer( m_VbBox, m_VblBox );
	m_VaBox->SetIndexBuffer( m_IbBox );

	m_Shader = std::make_shared<Shader>( "Resources/Shaders/Vertex.shader", "Resources/Shaders/Fragment.shader" );
	m_Shader->Bind();
	m_Shader->SetUniform1i( "u_Texture", 0 );

	m_TextureEntity = std::make_shared<Texture>( "Resources/Textures/sasa.png" );
	m_TextureGround = std::make_shared<Texture>( "Resources/Textures/ground.jpg" );
	m_TextureBox = std::make_shared<Texture>( "Resources/Textures/box.jpg" );
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
	//m_Systems->Swarm->Tick( dt );
	m_Systems->Movement->Tick( dt );
	//m_Systems->Draw->Tick( dt );
	m_Systems->Time->Tick( dt );
}

void SandboxScene::OnRender()
{
	glClearColor( m_ClearColor.x, m_ClearColor.y, m_ClearColor.z, m_ClearColor.w );
	m_Shader->Bind();

	m_TextureEntity->Bind();
	for ( auto &pos : m_Components->Positions.GetContainer() )
	{
		auto &mod = m_Components->Models.Find( pos.first );
		glm::mat4 model = glm::translate( glm::mat4( 1.0f ), pos.second.Position ) * glm::eulerAngleXZY( pos.second.Rotation.x, pos.second.Rotation.y, pos.second.Rotation.z ) * glm::scale( glm::mat4( 1.0f ), glm::vec3( ( float )mod.Size ) );
		glm::mat4 mvp = Renderer::m_Camera->m_Proj * Renderer::m_Camera->m_View * model;
		m_Shader->SetUniformMat4f( "u_MVP", mvp );
		Renderer::Draw( *m_VaEntity, *m_Shader );
	}

	m_TextureGround->Bind();
	const glm::vec3 posg( 0, 0, 0 );
	const glm::vec3 rotg( 0, 0, 0 );
	const float scaleg = 1.0f;
	const glm::mat4 modelg = glm::translate( glm::mat4( 1.0f ), posg ) * glm::eulerAngleXZY( rotg.x, rotg.y, rotg.z ) * glm::scale( glm::mat4( 1.0f ), glm::vec3( scaleg ) );
	glm::mat4 mvpg = Renderer::m_Camera->m_Proj * Renderer::m_Camera->m_View * modelg;
	m_Shader->SetUniformMat4f( "u_MVP", mvpg );
	Renderer::Draw( *m_VaGround, *m_Shader );

	const glm::vec3 posb1( 0, 0, 0 );
	const glm::vec3 rotb1( 0, 0, 0 );
	const glm::vec3 sizeb1( 0.1f, 0.1f, 0.1f );
	Renderer::DrawCube( posb1, rotb1, sizeb1, m_Shader.get(), m_TextureBox.get() );

	const glm::vec3 posb2( 0, 0.5, 0 );
	const glm::vec3 rotb2( 0, glm::radians( +45.0f ), 0 );
	const glm::vec3 sizeb2( 0.1f, 0.1f, 0.1f );
	Renderer::DrawCube( posb2, rotb2, sizeb2, m_Shader.get(), m_TextureBox.get() );

	const glm::vec3 posb3( -0.5, 0, 0 );
	const glm::vec3 rotb3( 0, glm::radians( -45.0f ), 0 );
	const glm::vec3 sizeb3( 0.1f, 0.1f, 0.1f );
	Renderer::DrawCube( posb3, rotb3, sizeb3, m_Shader.get(), m_TextureBox.get() );
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

void SandboxScene::OnKeyCallback( GLFWwindow *window, int key, int scancode, int action, int mods )
{

}

void SandboxScene::OnScrollCallback( GLFWwindow *window, double xoffset, double yoffset )
{

}

void SandboxScene::OnMouseMoveCallback( GLFWwindow *window, double xpos, double ypos )
{

}

void SandboxScene::OnMouseClickCallback( GLFWwindow *window, int button, int action, int mods )
{

}

