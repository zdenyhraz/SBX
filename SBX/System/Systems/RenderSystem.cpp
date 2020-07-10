#include "RenderSystem.h"
#include "Render/VertexArray.h"
#include "Render/VertexBuffer.h"
#include "Render/VertexBufferLayout.h"
#include "Render/IndexBuffer.h"
#include "Render/Shader.h"
#include "Render/Renderer.h"
#include "Render/Texture.h"

RenderSystem::RenderSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Render", true ),
	m_WindowName( "SBX OpenGL" ),
	m_WindowWidth( 2000 ),
	m_WindowHeight( 1500 )
{
	m_AspectRatioReversed = ( float )m_WindowHeight / m_WindowWidth;
}

void RenderSystem::Tick()
{
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
	vbl.Push<float>( 2 );//vertex position
	vbl.Push<float>( 2 );//texture coordinate
	va.AddBuffer( vb, vbl );
	IndexBuffer ib( indices, 6 );

	//model view projection matrix (M V P) -> (model)*(view)*(projection) in that order (however maths - reversed)
	glm::mat4 proj = glm::ortho( -1.0f, 1.0f, -m_AspectRatioReversed, m_AspectRatioReversed, -1.0f, 1.0f );
	glm::mat4 view = glm::translate( glm::mat4( 1.0f ), glm::vec3( 0, 0, 0 ) );

	Shader sh( "Resources/Shaders/Vertex.shader", "Resources/Shaders/Fragment.shader" );
	sh.Bind();
	sh.SetUniform1i( "u_Texture", 0 );

	Texture texture( "Resources/Textures/sasa.png" );
	texture.Bind();

	va.Unbind();
	vb.Unbind();
	ib.Unbind();
	sh.Unbind();

	Renderer renderer;

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	//ImGuiIO &io = ImGui::GetIO();( void )io;
	ImGui_ImplGlfw_InitForOpenGL( m_Window, true );
	ImGui_ImplOpenGL3_Init( ( char * )glGetString( GL_NUM_SHADING_LANGUAGE_VERSIONS ) );

	glm::vec3 translationA( 0, 0, 0 );
	glm::vec3 translationB( 0, 0, 0 );
	sh.Bind();

	while ( !glfwWindowShouldClose( m_Window ) )
	{
		renderer.Clear();

		{
			glm::mat4 modelA = glm::translate( glm::mat4( 1.0f ), translationA );
			glm::mat4 mvpA = proj * view * modelA;
			sh.SetUniformMat4f( "u_MVP", mvpA );
			renderer.Draw( va, ib, sh );
		}

		{
			glm::mat4 modelB = glm::translate( glm::mat4( 1.0f ), translationB );
			glm::mat4 mvpB = proj * view * modelB;
			sh.SetUniformMat4f( "u_MVP", mvpB );
			renderer.Draw( va, ib, sh );
		}

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
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