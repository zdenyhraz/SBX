#include "Scene.h"

Scene::Scene() :
	m_Enabled( false ),
	m_WindowName( "SBX OpenGL" ),
	m_WindowWidth( 2000 ),
	m_WindowHeight( 1500 )
{
	m_AspectRatio = ( float )m_WindowWidth / m_WindowHeight;
}

inline Scene::~Scene()
{

}

void Scene::Run()
{
	m_Enabled = true;

	glfwInit();
	m_Window = glfwCreateWindow( m_WindowWidth, m_WindowHeight, m_WindowName.c_str(), NULL, NULL );
	glfwMakeContextCurrent( m_Window );
	glfwSwapInterval( 1 );
	glewInit();
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	LOG_INFO( "SBX using OpenGL version {}", glGetString( GL_VERSION ) );

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

	VertexArray va;
	VertexBuffer vb( positions, 4 * 4 * sizeof( float ) );
	VertexBufferLayout vbl;
	vbl.Push<float>( 2 ); //vertex position
	vbl.Push<float>( 2 ); //texture coordinate
	va.AddBuffer( vb, vbl );
	IndexBuffer ib( indices, 6 );

	//model view projection matrix (M V P) -> (model)*(view)*(projection) in that order (however maths - reversed)
	glm::mat4 proj = glm::ortho( -1.0f, 1.0f, -1.0f / m_AspectRatio, 1.0f / m_AspectRatio, -1.0f, 1.0f );
	glm::mat4 view = glm::translate( glm::mat4( 1.0f ), glm::vec3( 0, 0, 0 ) );

	m_Shader = std::make_unique<Shader>( "Resources/Shaders/Vertex.shader", "Resources/Shaders/Fragment.shader" );
	m_Shader->Bind();
	m_Shader->SetUniform1i( "u_Texture", 0 );

	Texture texture( "Resources/Textures/sasa.png" );
	texture.Bind();

	va.Unbind();
	vb.Unbind();
	ib.Unbind();
	m_Shader->Unbind();

	m_Renderer = std::make_unique<Renderer>();
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	//ImGuiIO &io = ImGui::GetIO();( void )io;
	ImGui_ImplGlfw_InitForOpenGL( m_Window, true );
	ImGui_ImplOpenGL3_Init( ( char * )glGetString( GL_NUM_SHADING_LANGUAGE_VERSIONS ) );

	glm::vec3 translationA( 0, 0, 0 );
	glm::vec3 translationB( 0, 0, 0 );
	m_Shader->Bind();

	while ( !glfwWindowShouldClose( m_Window ) )
	{
		m_Renderer->Clear();

		OnUpdate();
		OnRender();

		{
			glm::mat4 modelA = glm::translate( glm::mat4( 1.0f ), translationA );
			glm::mat4 mvpA = proj * view * modelA;
			m_Shader->SetUniformMat4f( "u_MVP", mvpA );
			m_Renderer->Draw( va, ib, *m_Shader );
		}

		{
			glm::mat4 modelB = glm::translate( glm::mat4( 1.0f ), translationB );
			glm::mat4 mvpB = proj * view * modelB;
			m_Shader->SetUniformMat4f( "u_MVP", mvpB );
			m_Renderer->Draw( va, ib, *m_Shader );
		}

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		OnImGuiRender();

		{
			ImGui::Begin( "ModelViewProjection matrix" );
			ImGui::SetWindowFontScale( 1.5 );

			ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate );
			ImGui::NewLine();
			ImGui::SliderFloat3( "translation A", &translationA.x, -1.0f, 1.0f );
			ImGui::SliderFloat3( "translation B", &translationB.x, -1.0f, 1.0f );

			ImGui::End();
		}
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );

		glfwSwapBuffers( m_Window );
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow( m_Window );
	glfwTerminate();
}

void Scene::Kill()
{
	m_Enabled = false;
}
