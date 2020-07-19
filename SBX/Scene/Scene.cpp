#include "Scene.h"

Scene::Scene() :
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
	GlfwStart();
	ImGuiStart();
	OnGLInit();

	while ( !glfwWindowShouldClose( m_Window ) )
	{
		OnUpdate();
		OnRender();
		ImgGuiNewFrame();
		OnImGuiRender();
		ImGuiRender();
		GlfwRender();
	}

	ImGuiStop();
	GlfwStop();
}

void Scene::GlfwStart()
{
	glfwInit();
	m_Window = glfwCreateWindow( m_WindowWidth, m_WindowHeight, m_WindowName.c_str(), NULL, NULL );
	glfwMakeContextCurrent( m_Window );
	glfwSwapInterval( 1 );
	glewInit();
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	LOG_INFO( "SBX using OpenGL version {}", glGetString( GL_VERSION ) );
}

void Scene::GlfwStop()
{
	glfwDestroyWindow( m_Window );
	glfwTerminate();
}

void Scene::GlfwRender()
{
	glfwSwapBuffers( m_Window );
	glfwPollEvents();
}

void Scene::ImGuiStart()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL( m_Window, true );
	ImGui_ImplOpenGL3_Init( ( char * )glGetString( GL_NUM_SHADING_LANGUAGE_VERSIONS ) );
}

void Scene::ImGuiStop()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void Scene::ImgGuiNewFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Scene::ImGuiRender()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );
}
