#include "SandboxScene.h"

SandboxScene::SandboxScene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems ):
	Scene( components, managers, systems ),
	m_ClearColor( 0.f, 69.f / 255, 204.f / 255, 1.f )
{

}

void SandboxScene::OnStart()
{
	int initEntityCnt = 120;
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

	if ( true )
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


	m_VaEntity = std::make_unique<VertexArray>();
	VertexBuffer vbe( positionsEntity, 4 * 5 * sizeof( float ) );
	VertexBufferLayout vble;
	vble.Push<float>( 3 ); //vertex position
	vble.Push<float>( 2 ); //texture coordinate
	m_VaEntity->AddBuffer( vbe, vble );
	vbe.Unbind();

	m_VaGround = std::make_unique<VertexArray>();
	VertexBuffer vbg( positionsGround, 4 * 5 * sizeof( float ) );
	VertexBufferLayout vblg;
	vblg.Push<float>( 3 ); //vertex position
	vblg.Push<float>( 2 ); //texture coordinate
	m_VaGround->AddBuffer( vbg, vblg );
	vbg.Unbind();

	m_VaBox = std::make_unique<VertexArray>();
	VertexBuffer vbb( positionsBox, 8 * 5 * sizeof( float ) );
	VertexBufferLayout vblb;
	vble.Push<float>( 3 ); //vertex position
	vble.Push<float>( 2 ); //texture coordinate
	m_VaBox->AddBuffer( vbb, vblb );
	vbb.Unbind();

	m_Ib = std::make_unique<IndexBuffer>( indices, 6 );
	m_IbBox = std::make_unique<IndexBuffer>( indicesBox, 36 );

	m_Shader = std::make_unique<Shader>( "Resources/Shaders/Vertex.shader", "Resources/Shaders/Fragment.shader" );
	m_Shader->Bind();
	m_Shader->SetUniform1i( "u_Texture", 0 );

	m_TextureEntity = std::make_unique<Texture>( "Resources/Textures/sasa.png" );
	m_TextureGround = std::make_unique<Texture>( "Resources/Textures/ground.png" );
	m_TextureBox = std::make_unique<Texture>( "Resources/Textures/box.png" );

	m_Camera3D = std::make_unique<Camera3D>( m_AspectRatio );

	m_VaEntity->Unbind();
	m_VaGround->Unbind();
	m_VaBox->Unbind();
	m_Ib->Unbind();
	m_IbBox->Unbind();
	m_Shader->Unbind();
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

	m_Camera3D->Update( m_UserInput );
}

void SandboxScene::OnRender()
{
	glClearColor( m_ClearColor.x, m_ClearColor.y, m_ClearColor.z, m_ClearColor.w );

	m_TextureEntity->Bind();
	for ( auto &pos : m_Components->Positions.GetContainer() )
	{
		auto &mod = m_Components->Models.Find( pos.first );
		glm::mat4 model = glm::translate( glm::mat4( 1.0f ), pos.second.Position ) * glm::scale( glm::mat4( 1.0f ), glm::vec3( ( float )mod.Size ) ) * glm::eulerAngleXZY( pos.second.Rotation.x, pos.second.Rotation.y, pos.second.Rotation.z );
		glm::mat4 mvp = m_Camera3D->m_Proj * m_Camera3D->m_View * model;
		m_Shader->SetUniformMat4f( "u_MVP", mvp );
		Renderer::Draw( *m_VaEntity, *m_Ib, *m_Shader );
	}

	m_TextureGround->Bind();
	glm::mat4 mvpg = m_Camera3D->m_Proj * m_Camera3D->m_View;
	m_Shader->SetUniformMat4f( "u_MVP", mvpg );
	Renderer::Draw( *m_VaGround, *m_Ib, *m_Shader );

	m_TextureBox->Bind();
	glm::mat4 mvpb = m_Camera3D->m_Proj * m_Camera3D->m_View;
	m_Shader->SetUniformMat4f( "u_MVP", mvpb );
	Renderer::Draw( *m_VaBox, *m_IbBox, *m_Shader );
}

void SandboxScene::OnImGuiRender()
{
	ImGui::Begin( "Stuffs" );
	ImGui::SetWindowFontScale( 1.5 );
	ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate );
	ImGui::NewLine();
	ImGui::ColorEdit4( "Clear color", &m_ClearColor.x );
	ImGui::SliderFloat3( "Camera position", &m_Camera3D->m_ViewPos.x, -5, 5 );
	ImGui::SliderFloat3( "Camera direction", &m_Camera3D->m_ViewDir.x, -5, 5 );
	ImGui::SliderFloat( "Camera Fov", &m_Camera3D->m_CameraFov, 5.0f, 180.f );
	ImGui::SliderFloat( "Camera pitch", &m_Camera3D->m_Pitch, 1.f, 179.f );
	ImGui::SliderFloat( "Camera yaw", &m_Camera3D->m_Yaw, -180, 180 );
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

