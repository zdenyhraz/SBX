#include "TestScene.h"

TestScene::TestScene():
	Scene(),
	m_ClearColor{0.3, 0.1, 0.3, 1},
	m_TranslationA( 0, 0, 0 ),
	m_TranslationB( 0, 0, 0 )
{

}

TestScene::~TestScene()
{

}

void TestScene::OnGLInit()
{
	float positions[] =
	{
		-0.25f, -0.25f, 0.0f, 0.0f,
		+0.25f, -0.25f, 1.0f, 0.0f,
		+0.25f, +0.25f, 1.0f, 1.0f,
		-0.25f, +0.25f, 0.0f, 1.0f
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	m_Va = std::make_unique<VertexArray>();
	VertexBuffer vb( positions, 4 * 4 * sizeof( float ) );
	VertexBufferLayout vbl;
	vbl.Push<float>( 2 ); //vertex position
	vbl.Push<float>( 2 ); //texture coordinate
	m_Va->AddBuffer( vb, vbl );
	vb.Unbind();
	m_Ib = std::make_unique<IndexBuffer>( indices, 6 );

	//model view projection matrix (M V P) -> (model)*(view)*(projection) in that order (however maths - reversed)
	m_Proj = glm::ortho( -1.0f, 1.0f, -1.0f / m_AspectRatio, 1.0f / m_AspectRatio, -1.0f, 1.0f );
	m_View = glm::translate( glm::mat4( 1.0f ), glm::vec3( 0, 0, 0 ) );

	m_Shader = std::make_unique<Shader>( "Resources/Shaders/Vertex.shader", "Resources/Shaders/Fragment.shader" );
	m_Shader->Bind();
	m_Shader->SetUniform1i( "u_Texture", 0 );

	Texture texture( "Resources/Textures/sasa.png" );
	texture.Bind();

	m_Va->Unbind();
	m_Ib->Unbind();
	m_Shader->Unbind();
	m_Renderer = std::make_unique<Renderer>();
	m_Shader->Bind();
}

void TestScene::OnUpdate()
{
	//ticks
}

void TestScene::OnRender()
{
	glClearColor( m_ClearColor.x, m_ClearColor.y, m_ClearColor.z, m_ClearColor.w );
	glClear( GL_COLOR_BUFFER_BIT );

	{
		glm::mat4 modelA = glm::translate( glm::mat4( 1.0f ), m_TranslationA );
		glm::mat4 mvpA = m_Proj * m_View * modelA;
		m_Shader->SetUniformMat4f( "u_MVP", mvpA );
		m_Renderer->Draw( *m_Va, *m_Ib, *m_Shader );
	}

	{
		glm::mat4 modelB = glm::translate( glm::mat4( 1.0f ), m_TranslationB );
		glm::mat4 mvpB = m_Proj * m_View * modelB;
		m_Shader->SetUniformMat4f( "u_MVP", mvpB );
		m_Renderer->Draw( *m_Va, *m_Ib, *m_Shader );
	}
}

void TestScene::OnImGuiRender()
{
	{
		ImGui::Begin( "ModelViewProjection matrix" );
		ImGui::SetWindowFontScale( 1.5 );

		ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate );
		ImGui::NewLine();
		ImGui::SliderFloat3( "translation A", &m_TranslationA.x, -1.0f, 1.0f );
		ImGui::SliderFloat3( "translation B", &m_TranslationB.x, -1.0f, 1.0f );
		ImGui::ColorEdit4( "Clear color", &m_ClearColor.x );
		ImGui::End();
	}
}
